
#include <LiquidCrystal.h> //Load Liquid Crystal Library
LiquidCrystal LCD(11,10,9,2,3,4,5);  //Create Liquid Crystal Object called LCD

int lightPin = 0;  //pin for Photoresistor
int TranslateAnalog = 0;

void setup() 
{  
  Serial.begin(9600);  //Start serial communication
  pinMode (7, OUTPUT);
  LCD.begin(16,2); //Tell Arduino to start your 16 column 2 row LCD
}

void loop() {
  TranslateAnalog = analogRead(lightPin);
  if(TranslateAnalog>355) {
    LCD.clear();
    LCD.setCursor(0,0);  //Set LCD cursor to upper left corner, column 0, row 0
  LCD.print("ROOM LIGHT");  //Print Message on First Row
      digitalWrite(7, LOW);
      LCD.setCursor(0,1);   //Set Cursor again to first column of second row     
      LCD.print("TURN OFF");  //Print your units.
      delay(5000); //TURN ON LIGHT AFTER 5000 MILISECONDS      
    }
    //If Photoreistor Value is below 355 it will turn LED ON
    if(TranslateAnalog<355) {
      LCD.clear();
      LCD.setCursor(0,0);  //Set LCD cursor to upper left corner, column 0, row 0
  LCD.print("ROOM LIGHT");  //Print Message on First Row
      digitalWrite(7, HIGH);
      LCD.setCursor(0,1);   //Set Cursor again to first column of second row
      LCD.print("TURN ON");  //Print your units.
      delay(5000);//TURN OFF LIGHT AFTER 5000 MILISECONDS      
    }
   
  }