
/*
TODO
- 
*/

/***************************************
MAKE SURE YOU ARE RUNNING THE TEENSY2.0 
AT 8MHZ ONLY IN 3.3V MODE
**************************************/

/* Marker Layout
  0   7 
 1     6
 8  8  9
 2     5
  3 9 4 
*/

/* Pin Layout (based on Teensy 2.0)
  14   21 
 15     20
  5  5  4
 16     19
  17 4 18
 
 0 = status led
 13,12,11,10,9,6,3,2,1 = unused pins
 7 = Rx, 8 = Tx 
*/

/* Pins mandatory for detection */
//P4B9 - bottom center, right center
int B9 = 4;
//P5B9 - center most,left center 
int B8 = 5;

/* Status led (white) */
int statusLed = 0;

//Pins for 8 bits, 0...7
int markerPins[] = {14, 15, 16, 17, 18, 19, 20, 21};

void setup() {
  pinMode(B8, OUTPUT);
  pinMode(B9, OUTPUT);
  pinMode(statusLed, OUTPUT);
  
  for(int i=0; i<8; i++) {
    pinMode(markerPins[i], OUTPUT);
  }
  
  startTangible();
}

void loop() {
  /*Setting the marker to ff so that leds can be controlled manually using dip switch*/
  setMarkerValue(0xff);
  delay(2000);
}

void startTangible() {
  //Start mandatory marks
  digitalWrite(B8, HIGH);
  digitalWrite(B9, HIGH);
  digitalWrite(statusLed, HIGH);
  
  /*Setting everything else off*/
  /*
  for(int i = 0; i < 8, i++) { 
    digitalWrite(markerPins[i], LOW);
  }
  */
}

/*Reads a bit at index i and sets the marker pin corresponding to it high*/
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
}

void resetTangible() {
  stopTangible();
  startTangible();
}
