#define myServoPin 3                            
#define theButton 2 
#define myServoInterval 28                      // 2500/90=27.8 = 2.5 segundos a dividir por 90 angulos -> 27.5 milles/angulo
#include <Servo.h>                              
Servo myServo;
byte myServoPos = 90;
int flag = 0;                                  // Controle de giro
unsigned long currentMillis;                    
unsigned long previousMillis;                             
//--------------------------------------
enum                                            
{
  no_move_state,                               
  from_90_to_0,                                 
  from_0_to_90,                                 
  from_90_to_180,                               
  from_180_to_90                                
} 
currentState = no_move_state;                                   
//--------------------------------------
void setup()
{  
  pinMode (theButton, INPUT_PULLUP);                             // para evitar o estado de alta inpedancia
  myServo.attach(myServoPin);                   
  myServo.write(myServoPos);                    
}
//--------------------------------------
void loop()
{
  if (digitalRead(theButton) == LOW)                              // Se theButton foi pressionado
  {                                           
    if (digitalRead(theButton) == LOW)                          // Se theButton continua pressionado
    {
      flag = 1;                                                 // Permite movimento do motor
    }
  }
  if (flag == 1)                                                  // Se permitiu movimento, faça
  {
    switch (currentState)                       
    {
      case no_move_state:     
        currentState = from_90_to_0;                    
        break;
//------------------------------------------- 
      case from_90_to_0:                      
        currentMillis = millis();

        if (currentMillis - previousMillis 
        >= myServoInterval)                                                    //tempo atual - tempo previo é maior ou igual a intervalo de movimento do mutor
        {
          myServoPos = myServoPos - 1;          
          myServo.write(myServoPos);            
          previousMillis = currentMillis;       
        }
        if (myServoPos == 0)                    
        {
          currentState = from_0_to_90;          
        }
        break;
//----------------------------------------- 
      case from_0_to_90:
        currentMillis = millis();
        

        if (currentMillis - previousMillis 
        >= myServoInterval)
        {
          myServoPos = myServoPos + 1;
          myServo.write(myServoPos);
          previousMillis = currentMillis;
        }
        if (myServoPos == 90)
        {
          currentState = from_90_to_180;
        }
        break;
//-------------------------------------------- 
      case from_90_to_180:
        currentMillis = millis();

        
        if (currentMillis - previousMillis
        >= myServoInterval)
        {
          myServoPos = myServoPos + 1;
          myServo.write(myServoPos);
          previousMillis = currentMillis;
        }
        if (myServoPos == 180)
        {
          currentState = from_180_to_90;
        }
        break;
//------------------------------------------- 
      case from_180_to_90 :
        currentMillis = millis();

        if (currentMillis - previousMillis
        >= myServoInterval)
        {
          myServoPos = myServoPos - 1;
          myServo.write(myServoPos);
          previousMillis = currentMillis;
        }
        if (myServoPos == 90)
        {
          if (myServoPos == 90)
        {
          currentState = no_move_state;                                     // fazer reset
          flag = 0;                                                          // Bloqueia giro
        }
        break;
        }
     }
   }
}
