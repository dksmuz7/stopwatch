#include<LiquidCrystal.h>

long int t;
const int buzzerPin=6;
const int rs=13, en=12, d4=11, d5=10, d6=9, d7=8;//display pins
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);

void setup(){
    lcd.begin(16,2);

    pinMode(buzzerPin,OUTPUT);
    Serial.begin(9600);
}

void loop(){
    lcd.print("Enter Time(s)");
    lcd.setCursor(0,1);
    lcd.print("T(s) : ");
    lcd.print(t);
    Serial.print("T(s) : ");
    Serial.println(t);
    t = Serial.parseInt();

    if(t>0){
        for (int i=t;i>0;i--){
            lcd.clear();
            lcd.print("T(s) : ");
            lcd.print(t);
            Serial.print("T(s) : ");
            Serial.println(t);
            t--;
            delay(1000);
        }
        if(t==0){
            lcd.clear();
            lcd.print("Time Runout");
            digitalWrite(buzzerPin,HIGH);
            delay(3000);
            
        }
    }

    if(t<0){
        lcd.clear();
        lcd.print("Invalid Time");
        lcd.clear();
        lcd.print("Please Enter");
        lcd.setCursor(0,1);
        lcd.print("Valid time");
        t=0;
        delay(1000);
    }

    delay(10);
    digitalWrite(buzzerPin,LOW);
    lcd.clear();
}
