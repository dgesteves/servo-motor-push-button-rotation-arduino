#include <Servo.h>
#define buttonPin 2
#define servoPin 3

Servo servo;   

void setup() {
  Serial.begin(9600);
  servo.attach(servoPin);
 pinMode(buttonPin,INPUT_PULLUP);

}

void loop() {
  
  int posi = 90;    
  int buttonState;
  buttonState = digitalRead(buttonPin);
   if (buttonState == LOW) {
    servo.write (posi);
  
   for (posi = 90; posi >= 0; posi -= 1) {
    servo.write(posi);              
    delay(27);
    Serial.println(posi);   
  
}  
    for (posi = 0; posi <= 90; posi += 1) { 
    servo.write(posi);             
    delay(27);
    Serial.println(posi);   
                   
  }
  
  for (posi = 90; posi <= 180; posi += 1) {
    servo.write(posi);              
    delay(27);
    Serial.println(posi);
  }

    for (posi = 180; posi >= 90; posi -= 1) {
    servo.write(posi);              
    delay(27);
    Serial.println(posi);
    }
                      
  }
    
}   
