#include <Servo.h>

Servo myservo;

int potpin =0;
int val;
int led1=9;
int led2 =8;

void setup(){
    myservo.attach(13);
    pinMode (led1, OUTPUT);
    pinMode (led2, OUTPUT);
    pinMode (A0, INPUT);
}

void loop)(){
    if(digitalRead(A0) == LOW){
        digitalWrite(led1,1);
        digitalWrite(led2,0);
    }else {
        digitalWrite(led1,0);
        digitalWrite(led2,1);
    }

    val = analogRead(potin);
    val = map (val,0,1023,0,180);
    myservo.write(val);
    delay(15);
}