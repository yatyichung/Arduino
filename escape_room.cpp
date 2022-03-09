#include <Adafruit_NeoPixel.h>
#include <Servo.h>
#include <LiquidCrystal.h>

#define PIN 2 //input pin Neopixel is attached to
#define NUMPIXELS  12  //number of neopixels in strip

Adafruit_NeoPixel pixels = Adafruit_NeoPixel (NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
Servo myservo;
int delayval = 100;

int redColor = 0;
int greenColor = 0;
int blueColor = 0;

int question =0;
int locked = 0;

int pos=0;
const int trigPin =9;
const int echoPin=8;

long duration;

float distance = 110;
LiquidCrystal lcd(12,11,6,5,4,3);

const int buzzer = 10;
String password;

void setup(){
    Serial.begin(9600);
    //Initialize the NeoPixel library.
    pixels.begin();
    myservo.attact(7);
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    myservo.write(pos);
    lcd.begin(16,2);
    pinMode(A0,INPUT);
    pinMode(A1,INPUT);
    pinMode(A2,INPUT);
    pinMode(A3,INPUT);
    pinMode(10,OUTPUT);
}

void loop(){
    for (int 1=0; 1<NUMPIXELS; 1++){
        //pixels.Color takes RBC values, from 0,0,0 up to 255,255,255
        pixels.setPixelColor(i, pixels.Color(redColor,greenColor,blueColor));

        //this sends the updated pixel clolor to the hardware.
        pixels.show();

        //delay for a period of time (in milliseconds)
        delay(delayval);
    }

    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin. HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin,LOW);

    duration = pulseIn (echoPin, HIGH);
    distance = 0.024 * (duration/2);
    //serial.printIn (distance);

    if (distance>100 && locked ==0){
        setColor();
    }else if (distance < 100 && locked ==0){
        myservo.write(90);
        setOff();
        locked = 1;
        question = 1;
    }

    //question 1 displayed 
    if(question ==1){
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Q1: 1+1=?");
        lcd.setCursor(0,1);
        lcd.print("A)2 B)3 C)4 D)5");
        setOff();
    } else if (question ==2){     //question 2 displayed 
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Q2: 2+2=?");
        lcd.setCursor(0,1);
        lcd.print("A)2 B)3 C)4 D)5");
        setOff();
    }else if (question ==3){     //question 3 displayed 
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Q2: 2+1=?");
        lcd.setCursor(0,1);
        lcd.print("A)2 B)3 C)4 D)5");
        setOff();
    }else if (question ==4){     //question 4 displayed 
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Q2: 3+2=?");
        lcd.setCursor(0,1);
        lcd.print("A)2 B)3 C)4 D)5");
        setOff();
    }else if (question ==5){     //question 5 displayed 
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Q2: 0*1=?");
        lcd.setCursor(0,1);
        lcd.print("A)0 B)1 C)2 D)3");
        setOff();
    }else if (question ==6){     //question 6 displayed 
        Serial.printIn("Enter Password Here");
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Hint:coursecode");
        lcd.setCursor(0,1);
        lcd.print("1,2,4,8,9");
        setOff();
    }else if (question ==7){    
        lcd.clear();
        myservo.write(0);
        setColor();
            if(distance>100) {      //reset
                question = 0;
                locked =0;
            } 
    }

}