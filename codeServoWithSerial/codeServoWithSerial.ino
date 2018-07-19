#define myServoPin 3
#include <Servo.h>
Servo myServo;
int myServoPos = -60;                            //começa a -60
unsigned long tempoStep;
unsigned long temp = 0;                          //velocidade
int value = 0;                                  // digito encerido
int way = 1;                                    // sentido para que gira o motor
int control = 0;                                // funcao principal que serve de regulamento
int flag1 = 1;                                  //sentido 1
int flag2 = 1;                                  //sentido 2
float tempCalc = 0;                             //armazena o valor do tempo
//--------------------------------------
void setup()
{
  Serial.begin(9600);
  myServo.attach(myServoPin);
  myServo.write(myServoPos);
}
//--------------------------------------
void rotateServo()
{                                                  //funcao para o servo rodar
  if (flag2 == 0)                                  //se esta virado para a esquerda
  {
    tempCalc = (float)temp / 120;                //Velocidade a / 120 = aglos por segundo
    tempoStep = millis();                       //comesa a contar o tempo
    flag2 = 1;                                  //entao vira para a direita
  }
  if (control < 120)                               //se esta a menos de 120º
  {
    if ((millis() - tempoStep) > tempCalc)          //tempo atual menos tempo anterior maior que velocidade
    {
      control++;                                    //somar angulos
      myServoPos = myServoPos + way;                //posicao atual = posicao atual +1||-1
      tempoStep = millis();                          //comesa a contar o tempo
      myServo.write(myServoPos + 60);               //posiçao +||- 60 + 60
    }
  }
  if (control >= 120)                                     // se o servo esta na posicao >= a 120 entao....
  {
    way *= -1;                                        //faz resete e inverte o sentido
    value = 0;                                            
    flag2 = 0;
    flag1 = 1;                                         //activa o movimento contrario
    control = 0;                                       //faz reset do angulo onde esta o motor 
  }
}
//--------------------------------------
void loop()
{
  switch (flag1)
  {
    case 0:
      temp = (value * 500) + 500;                       //velocidade = (digito encerido * 500)+500 = 5 segundos
      rotateServo();
      break;

    case 1:
      if (Serial.available() > 0)                     // confima se esta informacao a ser resebida
      {
        value = Serial.parseInt();                    //digito = ao numero inteiro no Serial
        Serial.println(value);                       //imprime digito enviado
        flag1 = 0;
      }
      break;
  }
}
