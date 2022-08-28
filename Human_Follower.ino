/*NOTE: The Right_Value and Left_Value is not tested so if the white is detected then the value can be either 0 or 1 it can be ony tested when it is executed*/
 
#include<NewPing.h>  
#include<Servo.h>

#define RIGHT A2
#define LEFT A3
#define TRIGGER_PIN A1
#define ECHO_PIN A0
#define MAX_DISTANCE 200

unsigned int distance = 0;
unsigned int Right_Value = 0;
unsigned int Left_Value = 0;

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

int M1F = 2;//Left
int M1B = 3;//Left
int M2F = 4;//Right
int M2B = 5;//Right

 Servo myservo;
 int pos=0;

void setup() 
{
   Serial.begin(9600);
   myservo.attach(10);
  {
     for(pos = 90; pos <= 180; pos += 1)
     {    
        myservo.write(pos);                  
        delay(15);                            
     } 
     for(pos = 180; pos >= 0; pos-= 1) 
     {    
        myservo.write(pos);                  
        delay(15);                            
     }
     for(pos = 0; pos<=90; pos += 1) 
     {       
        myservo.write(pos);                  
        delay(15);                           
     }
  }
  pinMode(RIGHT, INPUT);
  pinMode(LEFT, INPUT);
}

void loop() 
{                             
   delay(50);                        
   distance = sonar.ping_cm();                  
   Serial.print("distance");                   
   Serial.println(distance);
   
   Right_Value = digitalRead(RIGHT);  
   Left_Value = digitalRead(LEFT); 
   
   Serial.print("RIGHT");                      
   Serial.println(Right_Value); 
   Serial.print("LEFT");                       
   Serial.println(Left_Value); 
    
   if((distance > 1) && (distance < 15))
   {  
      if((Right_Value==1) && (Left_Value==1))
      {
         digitalWrite(M1F,HIGH);
         digitalWrite(M1B,LOW);
         digitalWrite(M2F,HIGH);
         digitalWrite(M2B,LOW); 
      }
   
      else if((Right_Value==0) && (Left_Value==1)) 
      {       
         digitalWrite(M1F,HIGH);
         digitalWrite(M1B,LOW);
         digitalWrite(M2F,LOW);
         digitalWrite(M2B,HIGH); 
         delay(150);
      }
      else if((Right_Value==1)&&(Left_Value==0)) 
      {   
         digitalWrite(M1F,LOW);
         digitalWrite(M1B,HIGH);
         digitalWrite(M2F,HIGH);
         digitalWrite(M2B,LOW); 
         delay(150);
      }
      else 
      {
         digitalWrite(M1F,LOW);
         digitalWrite(M1B,HIGH);
         digitalWrite(M2F,HIGH);
         digitalWrite(M2B,LOW); 
 
      }
   }
   else
   {
      {
         for(pos = 90; pos <= 180; pos += 1)
         {    
            myservo.write(pos);                  
            delay(15);                            
         } 
         for(pos = 180; pos >= 0; pos-= 1) 
         {    
            myservo.write(pos);                  
            delay(15);                            
         }
         for(pos = 0; pos<=90; pos += 1) 
         {       
            myservo.write(pos);                  
            delay(15);                           
         }
      }
   }
}
