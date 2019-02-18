#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
int inputPin = 2;
int pirState = LOW;
int val = 0;
int oPin = A0;
void setup()
{
  pinMode(oPin,OUTPUT);
	lcd.begin();
        lcd.noBacklight();
}

void loop()
{
	bool blinking = true;
	lcd.cursor();
        int m=6,h=6,o=4,t=0,i=0,yy=2017,d=21,mo=2,p,s=0,st=0,q=0;
        char c='P',ht=' ';
delay(5000);
	while (1) {
                val = digitalRead(inputPin);
	              if(val == HIGH){lcd.backlight();digitalWrite(oPin,val);}
                if(val == LOW){lcd.noBacklight();digitalWrite(oPin,val);}
                if(s==9){st++;s=-1;}
                if(m==9){q++;if(q==60){m=-1;o++;q=0;}}
                if(o==6){h++;o=0;}
                if(h==3){if(ht=='1'){ht=' ';h=1;}}
                if(h==10){ht='1';h=0;}
                if(ht=='1'){i++;if(i==7200){
                if(t==0){c='A'; d++; t=1;}
                else{c='P';t=0;}i=0;}}
                if(st==6){m++;st=0;}
                if(mo==1||mo==3||mo==5||mo==7||mo==8||mo==10){if(d==32){d=1;mo++;}}
                if(mo==4||mo==6||mo==9||mo==11){if(d==31){d=1;mo++;}}
                if(mo==2){if(d==29){d=1;mo++;}}
                if(mo==12){if(d==32){d=1;mo=1;yy++;}}
                s++;
                lcd.clear();
                lcd.print("   ");
                lcd.print(ht);
                lcd.print(h);
                lcd.print(":");
                lcd.print(o);
                lcd.print(m);
                lcd.print(":");
                lcd.print(st);
                lcd.print(s);
                lcd.print(c);
                lcd.print("M");
                lcd.setCursor(0, 1);
                lcd.print("    ");
                lcd.print(mo);
                lcd.print("/");
                lcd.print(d);
                lcd.print("/");
                lcd.print(yy);
                delay(958);
	}
}
