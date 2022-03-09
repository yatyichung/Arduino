int LED1 = 7;
int LED2 = 6;
int LED3 = 5;
int BUTTON1 = 4;
int BUTTON2= 3;

void setup(){
    pinMode(LED1,OUTPUT);
    pinMode(LED2,OUTPUT);
    pinMode(BUTTON1,INPUT);
    pinMode(BUTTON2,INPUT);
}

void loop(){
    if(digitalRead(BUTTON1) == HIGH){
        digitalWrite(LED1,1);
    } else {
        digitalWrite(LED1,0);
    }
    if(digitalRead(BUTTON2) == HIGH){
        digitalWrite(LED2,1);
    } else {
        digitalWrite(LED2,0);
    }
    if (digitalRead(BUTTON1) == HIGH && digitalRead(BUTTON2)== HIGH) { 
        digitalWrite(LED1,1);
        digitalWrite(LED2,1);
        digitalWrite (LED3,1);
    } else {
        digitalWrite(LED1,0);
        digitalWrite (LED2,0);
        digitalWrite (LED3,0);
    }
}
