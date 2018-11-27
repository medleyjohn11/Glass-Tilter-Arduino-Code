
//Enter Glass Angle Here
const int glassAngle = -30;

//Enter Angle of glass at home here
const int homeAngle= 53.5;

const int homePin = 3;   
const int ledPin =  4;

const int stepPin = 5; 
const int dirPin = 6;
int homeState = 0;
int homeN = 1;

void setup() {                
 
   // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(homePin, INPUT);
  
  pinMode(stepPin,OUTPUT); 
pinMode(dirPin,OUTPUT);
int homeN = 1;
}

void loop() {


if (homeN==1){  
for(int q = 0;q<2;){



//this is the homing sequence
 digitalWrite(dirPin,LOW); //Changes the rotations direction
  // Makes x pulses 200 = full turn
  for(int x = 0; x < 1; x++) {
    digitalWrite(stepPin,HIGH);
    delayMicroseconds(10000);
    digitalWrite(stepPin,LOW);
    delayMicroseconds(10000);}
    delay(10);
    homeState = digitalRead(homePin);
    if(homeState == HIGH){ q=2;}
}
homeN=2;
}


//this moves the glass to the specified angle
 if (homeN==2){  

int moveto = ((homeAngle - glassAngle)/0.65 + 5/.65);
 digitalWrite(dirPin,HIGH); //Changes the rotations direction
  // Makes x pulses 200 = full turn
  for(int x = 0; x < moveto; x++) {
    digitalWrite(stepPin,HIGH);
    delayMicroseconds(20000);
    digitalWrite(stepPin,LOW);
    delayMicroseconds(20000);}
   

homeN=3;
}
homeState = digitalRead(homePin);
    if(homeState == HIGH){
       digitalWrite(ledPin,HIGH);
for(int x = 0; x < 5; x++) {
    digitalWrite(stepPin,HIGH);
    delayMicroseconds(10000);
    digitalWrite(stepPin,LOW);
    delayMicroseconds(10000);}
    delay(500);}
    else{digitalWrite(ledPin,LOW);}
}
