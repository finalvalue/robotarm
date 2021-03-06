// VarSpeedServo - Version: Latest 
#include <Servo.h>

#include <EEPROM.h>

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;

int potpin1 = 0;

int val1[7]={90,154,154,154,90,90,90};
int val2[7]={48,48,0,0,0,0,48};
int val3[7]={55,55,100,100,100,100,55};
int val4[7]={45,45,64,128,128,45,45};

int cc;
int stp;
int x;
void setup()
{
  cc=0;
  servo1.attach(11);               
  servo2.attach(10);  
  servo3.attach(9);               
  servo4.attach(6);
  Serial.begin(9600);
  x=20;
  servo1.write(val1[cc]);
  servo2.write(val2[cc]);
  servo3.write(val3[cc]);
  servo4.write(val4[cc]);
}
void loop()
{ 
  for(cc=0;cc<=5;cc+=1){
    ///velocidade
    x = analogRead(potpin1);
    x = map (x, 0, 1023, 1, 100);
    ///servo1
    Serial.println("----------");
    Serial.print("delay: ");
    Serial.println(x);
    Serial.println(cc);
    Serial.print("Servo1:");
    Serial.print(val1[cc]);
    Serial.print("->");
    Serial.println(val1[cc+1]); 
    if(val1[cc+1]>val1[cc]){
      for(stp=val1[cc];stp<=val1[cc+1];stp+=1){
         servo1.write(stp); 
         delay(x);
      }
    }else if(val1[cc+1]<val1[cc]){
      for(stp=val1[cc];stp>=val1[cc+1];stp-=1){
         servo1.write(stp); 
         delay(x);
      }
    }
    
    ///servo2
    Serial.print("Servo2:");
    Serial.print(val2[cc]);
    Serial.print("->");
    Serial.println(val2[cc+1]); 
    if(val2[cc+1]>val2[cc]){
      for(stp=val2[cc];stp<=val2[cc+1];stp+=1){
         servo2.write(stp); 
         delay(x);
      }
    }else if(val2[cc+1]<val2[cc]){
      for(stp=val2[cc];stp>=val2[cc+1];stp-=1){
         servo2.write(stp); 
         delay(x);
      }
    }
    ///servo3
    Serial.print("Servo3:");
    Serial.print(val3[cc]);
    Serial.print("->");
    Serial.println(val3[cc+1]); 
    if(val3[cc+1]>val3[cc]){
      for(stp=val3[cc];stp<=val3[cc+1];stp+=1){
         servo3.write(stp); 
         delay(x);
      }
    }else if(val3[cc+1]<val3[cc]){
      for(stp=val3[cc];stp>=val3[cc+1];stp-=1){
         servo3.write(stp); 
         delay(x);
      }
    }
    ///servo4
    Serial.print("Servo4:");
    Serial.print(val4[cc]);
    Serial.print("->");
    Serial.println(val4[cc+1]); 
    if(val4[cc+1]>val4[cc]){
      for(stp=val4[cc];stp<=val4[cc+1];stp+=1){
         servo4.write(stp); 
         delay(x);
      }
    }else if(val4[cc+1]<val4[cc]){
      for(stp=val4[cc];stp>=val4[cc+1];stp-=1){
         servo4.write(stp); 
         delay(x);
      }
    }
          
  }
  delay(1000);
}









