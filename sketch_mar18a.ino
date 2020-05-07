#include <Wire.h>
#include "Adafruit_TCS34725.h"


Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X);


const int in1 = 8;     
const int in2 = 9;     
const int in3 =  10;
const int in4 =  11;
const int enA = 5;  
const int enB = 6;

char val = ' ' ;
char temp = ' ' ;
void setup() {
Serial.begin(9600);


  if (!tcs.begin()) {                   
    Serial.print("No Sensor Found - Halting Program");
    while (1);
  }
}

void loop() {

  
  uint16_t clear, red, green, blue;

   

  tcs.getRawData(&red, &green, &blue, &clear);

  Serial.print("C:\t"); Serial.print(clear);
//  Serial.print("\tR:\t"); Serial.print(red);
//  Serial.print("\tG:\t"); Serial.print(green);
//  Serial.print("\tB:\t"); Serial.print(blue);
 
  // Figure out some basic hex code for visualization
  uint32_t sum = clear;
  float r, g, b;
  r = red; r /= sum;
  g = green; g /= sum;
  b = blue; b /= sum;
  r *= 256; g *= 256; b *= 256;
//  Serial.print("\t");
//  Serial.print((int)r, HEX); Serial.print((int)g, HEX); Serial.print((int)b, HEX);
 Serial.println(); 

  char val = Serial.read();

 while (Serial.available () == 1 ) { 

 
  temp = val ;

             
   if ( (temp == 'a') && (clear<160) && (120<clear)){
      Serial.print("Black");
      // sol
     digitalWrite(in1, LOW);
     digitalWrite(in2,  HIGH);  
     analogWrite(enA, 140);
     
     // motor sağ
     
     digitalWrite(in3, HIGH);
     digitalWrite(in4,  LOW);
     analogWrite(enB,  140);
     
     }


    else if ( (temp == 'r' )&& (170<clear)&&(clear<200) ){  
      Serial.print("Red");

    //motor sol
     digitalWrite(in1, LOW);
     digitalWrite(in2,  HIGH);  
     analogWrite(enA, 100);
   // motor sağ
     digitalWrite(in3, HIGH);
     digitalWrite(in4,  LOW);
     analogWrite(enB,  100);  
    }
  

    
    else if (( val == 'b' )&&  (clear<250)&&(200<clear) ){
      Serial.print("Blue");

   //motor sol
     digitalWrite(in1, LOW);
     digitalWrite(in2,  HIGH);  
     analogWrite(enA, 100);
   // motor sağ
     digitalWrite(in3, HIGH);
     digitalWrite(in4,  LOW);
     analogWrite(enB,  100);
    }

    

    
    else if ((val == 'y')&&(300<clear)&&(clear<305)){
      Serial.print("Yellow");
      //motor sol
     digitalWrite(in1, LOW);
     digitalWrite(in2,  HIGH);  
     analogWrite(enA, 120);
   // motor sağ
     digitalWrite(in3, HIGH);
     digitalWrite(in4,  LOW);
     analogWrite(enB,  120);
    }
    
     else if( (val == 's') ){
      
   //motor sol
     digitalWrite(in1, LOW);
     digitalWrite(in2,  HIGH);  
     analogWrite(enA, 0);
   // motor sağ
     digitalWrite(in3, HIGH);
     digitalWrite(in4,  LOW);
     analogWrite(enB,  0);  
        Serial.println("STOP AMK");
    }
    
    
//     if (( 316<=clear) && (clear<=328) ){
//       //motor sol
//     digitalWrite(in1, LOW);
//     digitalWrite(in2,  HIGH);  
//     analogWrite(enA, 140);
//       // motor sağ
//     digitalWrite(in3, HIGH);
//     digitalWrite(in4,  LOW);
//     analogWrite(enB,  0);
//     char val = Serial.read();
//
//       
//    }
    
     if (( 260<=clear) && (clear<=400) ){
       //motor sol
     digitalWrite(in1, LOW);
     digitalWrite(in2,  HIGH);  
     analogWrite(enA, 140);
       // motor sağ
     digitalWrite(in3, HIGH);
     digitalWrite(in4,  LOW);
     analogWrite(enB,  0);



   } 
  }
}
   
  
    

 
 


  



  
