
/*
TODO
- 
*/

// Pins mandatory for detection
//P17B8 - bottom center, right center
int B8 = 17;
//P14B9 - center most,left center 
int B9 = 14;

//Feedback leds
int greenLed = 10;
int redLed = 9;

//Pins for 8 bits, 0...7
int markerPins[] = {12, 13, 15, 16, 18, 19, 20, 21};

void setup() {
  pinMode(B8, OUTPUT);
  pinMode(B9, OUTPUT);
  for(int i=0; i<8; i++) {
    pinMode(markerPins[i], OUTPUT);
  }
  
}

void loop() {
  startTangible();
  setMarkerValue(0xc3);
  
  delay(4000);
}

void startTangible() {
  //Start mandatory marks
  digitalWrite(B8, HIGH);
  digitalWrite(B9, HIGH);

  //Setting everything else off
//  for(int i = 0; i < 8, i++) { 
//    digitalWrite(markerPins[i], LOW);
//  }
  
  //Set feedback
//  digitalWrite(greenLed, HIGH);
}

void setMarkerValue(int value) {
  //Light leds to create marker
  for(int i = 0; i < 8; i++) {
    if(bitRead(value, i)) {
      digitalWrite(markerPins[i], HIGH);
    } else {
      digitalWrite(markerPins[i], LOW);
    }    
  }
}

void stopTangible() {
  //Setting everything off
  digitalWrite(B8, LOW);
  digitalWrite(B9, LOW);
  
  for(int i = 0; i < 8; i++) {
    digitalWrite(markerPins[i], LOW);
  }
  
    //Set feedback
  digitalWrite(greenLed, LOW);
  digitalWrite(redLed, HIGH);
}
