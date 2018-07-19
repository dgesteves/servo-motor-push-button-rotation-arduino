#define DEBUG                           // Fazer prints sem ocupar tanto tempo no programa; facil remocao de todos os prints de uma so vez
#include <Servo.h>                     // incluir a biblioteca servo

Servo myServo;

byte myServoPos = 90;                  //começa nos 90º

byte myServoPin = 3;                   // servo no pin 3
byte theButton = 2;                    // butao no pin 2

enum                                   // enumeração para switch case
{

no_move_state,                         // estado parado
from_90_to_0,                         // primeiro movimento
from_0_to_90,                         // segundo movimento    
from_90_to_180,                       // terceiro movimento
from_180_to_90                        // quarto movimento

} 
currentState = no_move_state;          // estado atual sem movimento

unsigned long currentMillis;             // tempo atual
unsigned long previousMillis;            // tempo anterior


int myServoInterval = 28;               // 2500/90=27.8 = 2.5 segundos a dividir por 90 angulos -> 27.5 milles/angulo

#ifdef DEBUG
bool newMove = false;                   // Vew move é = 1 V = 0
unsigned long started_at;               // guardar o valor do tempo anterior
#endif

void setup()
{

#ifdef DEBUG
Serial.begin(9600);
#endif



pinMode (theButton, INPUT_PULLUP);      //para evitar o estado de alta inpedancia
myServo.attach(myServoPin);             //associar pin 3 ao motor
myServo.write(myServoPos);              // motor vai para aposicao atual


}

void loop()

{

switch (currentState)                   //Switch case function
{
case no_move_state:                     //case em que o motor esta parado

#ifdef DEBUG
Serial.println(" ");
Serial.println("waiting for button...");
#endif

while (digitalRead(theButton))
{
 
}
                                 


#ifdef DEBUG
Serial.println(" ");
Serial.println(" button pressed!!");
#endif

currentState = from_90_to_0;            //mover motor para de 90ºpara  0º

break;

case from_90_to_0:                     // caso em que o servo esta a 0º
currentMillis = millis();

#ifdef DEBUG
if (!newMove)
{
newMove = true;
started_at = currentMillis;          // funcao para obter tempo decorrido 90º a 0º
Serial.println(" ");
Serial.println("90º to 0º ");
}
#endif

if (currentMillis - previousMillis >= myServoInterval)   //tempo atual - tempo previo é maior ou igual a velocidade do mutor
{
myServoPos = myServoPos - 1;        // retirar 1 angulo a cada millie
myServo.write(myServoPos);          // mover servo para posicao atual = 0
previousMillis = currentMillis;      //fazer seter ao valor dos millies
}



if (myServoPos == 0)                  //se o servo esta na posicao 0º entao...
{
        
#ifdef DEBUG
Serial.println(" took: ");
Serial.println(currentMillis - started_at);
newMove = false;
#endif

currentState = from_0_to_90;         // mover servo pata 90º

}
break;

case from_0_to_90:  
currentMillis = millis();

#ifdef DEBUG
if (!newMove)
{
newMove = true;
started_at = currentMillis;
Serial.println(" ");
Serial.println("0º to 90º ");
}
#endif

if (currentMillis - previousMillis >= myServoInterval)
{
myServoPos = myServoPos + 1;
myServo.write(myServoPos);
previousMillis = currentMillis;
}



if (myServoPos == 90)
{

#ifdef DEBUG
Serial.println("took: ");
Serial.println(currentMillis - started_at);
newMove = false;
#endif

currentState = from_90_to_180;

}

break;
      
case from_90_to_180:  
currentMillis = millis();

#ifdef DEBUG
if (!newMove)
{
newMove = true;
started_at = currentMillis;
Serial.println(" ");
Serial.println("90º to 180º ");
}
#endif

if (currentMillis - previousMillis >= myServoInterval)
{
myServoPos = myServoPos + 1;
myServo.write(myServoPos);
previousMillis = currentMillis;
}



if (myServoPos == 180)
{
        
#ifdef DEBUG
Serial.println("took: ");
Serial.println(currentMillis - started_at);
newMove = false;
#endif


currentState = from_180_to_90;

}

break;

case from_180_to_90 : 
currentMillis = millis();
      
#ifdef DEBUG
if (!newMove)
{
newMove = true;
started_at = currentMillis;
Serial.println(" ");
Serial.println("180º to 90º ");
}
#endif

if (currentMillis - previousMillis >= myServoInterval)
{
        myServoPos = myServoPos - 1;
        myServo.write(myServoPos);
        previousMillis = currentMillis;
}



if (myServoPos == 90)
{
        
#ifdef DEBUG
Serial.println("took: ");
Serial.println(currentMillis - started_at);
newMove = false;
#endif

currentState = no_move_state;                      // fazer reset

}

break;

}

}

