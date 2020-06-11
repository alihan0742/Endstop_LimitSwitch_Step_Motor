// defines pins numbers
const int dirPin = 4;
const int stepPin = 5;
const int enable=6;
const int limitSw_1 = 2; 
const int limitSw_2 = 3; 


void setup() {

  pinMode(limitSw_2, INPUT); //lim2
  pinMode(limitSw_1, INPUT); //lim1
  pinMode(enable, OUTPUT); //Enable
  pinMode(stepPin, OUTPUT); //Step
  pinMode(dirPin, OUTPUT); //Direction

  //digitalWrite(enable,LOW);

  digitalWrite(dirPin,LOW); // Enables the motor to move in a particular direction

}

void loop() {

    int limSw1 = digitalRead( limitSw_1);
    int limSw2 = digitalRead( limitSw_2);
    
    if( limSw1 == HIGH && (digitalRead(dirPin) == LOW) ){
        motorStep(2000); 
    }

    else if( limSw1 == LOW && (digitalRead(dirPin) == LOW) ){
          digitalWrite(dirPin,HIGH);
          delay(2000);
    }
    else if( limSw2 == HIGH && (digitalRead(dirPin) == HIGH) ){
        motorStep(2000);
    }
    else if( limSw2 == LOW && (digitalRead(dirPin) == HIGH) ){
          digitalWrite(dirPin,LOW);
          delay(2000);
    }
    
    if( (digitalRead(dirPin) == HIGH) ){
        motorStep(2000); 
        digitalWrite(dirPin,HIGH);
        
    } 
    else if( (digitalRead(dirPin) == LOW) ){ 
        motorStep(2000); 
        digitalWrite(dirPin,LOW);
        
    }
}

void motorStep( int MAX){

   for(int x = 0; x < MAX; x++) {
        digitalWrite(stepPin,HIGH);
        delayMicroseconds(200);
        digitalWrite(stepPin,LOW);
        delayMicroseconds(200);}
}
