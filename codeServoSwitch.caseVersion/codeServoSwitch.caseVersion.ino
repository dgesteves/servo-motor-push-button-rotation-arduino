#include <Servo.h>
#define buttonPin 2
#define servoPin 3
Servo servo;
unsigned int cont = 0;                       //contagem para averiguar o estado da logica
boolean motor = 0;                           //ordem para o motor
int resetprogram = 0;
int startprogram = 0;




void setup() 
{
  Serial.begin(9600);
  servo.attach(servoPin);
 pinMode(buttonPin,INPUT_PULLUP);           // retirar o butao de estado de alta inpedancia

}


void loop()

{
  
boolean button_pressed = digitalRead(buttonPin);
  
if( (button_pressed == 1) && (motor == 0))       //se o botao estao percionado e o motor nao esta ligado
{
motor = 1;                                       // entao liga o motor
} 
if( (button_pressed == 0) && (motor == 1))      // se o botao nao esta precionado  e o motor esta ligado
{
motor = 0;                                      // entao desliga o motor
cont++;                                         // averiguaçao da logica
}
program();                                      // declarar a funcao programa
delay(10);                                       // tempo de resposta do botao
} 
  

void program()                                 //void criado para quebrar o loop e correr o prograna unicamente uma vez
{
Serial.println(cont);
switch(cont)
{
case 0:
if ( resetprogram == 0)                          // se o reset = 0 o programa esta a correr....
{
servo.write(90,);
delay (2500);
servo.write(0,);
delay (2500); 
servo.write(90,);
delay (2500); 
servo.write(180,);
delay (2500); 
servo.write(90,); 
resetprogram = 1;                                // o programa terminou faz reset
}
break;

case 1:
if ( startprogram == 0)                          // se o programa nao esta a correr entao faz um reset 
{
cont = 0;
resetprogram = 0;
startprogram = 0;
}
break;
}

}
