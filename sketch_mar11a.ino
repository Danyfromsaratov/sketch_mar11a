// constants won't change. Used here to set a pin number :
int Pin1 = 13;
int Pin2 = 12;
int Pin3 = 11;
int Pin4 = 10;
int Pin5 = 9;

// Variables will change :
int State1 = LOW;
int State2 = LOW;
int State3 = LOW;
int State4 = LOW;
int State5 = LOW;
// ledState used to set the LED


// Generally, you should use "unsigned long" for variables that hold time
// The value will quickly become too large for an int to store
unsigned long previousMillis1 = 0;
unsigned long previousMillis2 = 0;
unsigned long previousMillis3 = 0;
unsigned long previousMillis4 = 0;
unsigned long previousMillis5 = 0;// will store last time LED was updated

// constants won't change :
unsigned long interval1 = 1000000; // interval at which to blink (microseconds)
unsigned long interval2 = 500000;
unsigned long interval3 = 333;// interval at which to blink (milliseconds)
unsigned long interval4 = 250;
unsigned long interval5 = 100;

String stroka;
char words[10];
int pin;
unsigned long newinterval;
void setup() {
  // set the digital pin as output:
  Serial.begin(9600);
  pinMode(Pin1, OUTPUT);
  pinMode(Pin2, OUTPUT);
  pinMode(Pin3, OUTPUT);
  pinMode(Pin4, OUTPUT);
  pinMode(Pin5, OUTPUT);
}
void SerialEvent()
{
  stroka = Serial.read();
  stroka=stroka.toInt();
  stroka=stroka-48;
  Serial.print(stroka);
  stroka.toCharArray(words, 10);
  pin = atoi(strtok(words, "="));
  //newinterval = strtok(NULL, "=");

  

  if (pin == '1') {
    digitalWrite(13, 1);
    // block = true;
    interval1 = newinterval;
  }
  if (pin == '2') {
    digitalWrite(12, 1);
    // block = true;
    interval2 = newinterval;
  }
  if (pin == '3') {
    digitalWrite(11, 1);
    // block = true;
    interval3 = newinterval;
  }
  if (pin == '4') {
    digitalWrite(10, 1);
    // block = true;
    interval4 = newinterval;
  }
  if (pin == '5') {
    digitalWrite(9, 1);
    // block = true;
    interval5 = newinterval;
  }
}
void loop() {

  unsigned long currentMillis = millis();
  unsigned long currentMillis2 = millis();
  currentMillis2 = currentMillis2 * 0.001;
  if (currentMillis - previousMillis1 >= interval1) {
    // save the last time you blinked the LED
    previousMillis1 = currentMillis2;

    if (State1 == LOW) {
      State1 = HIGH;
    } else {
      State1 = LOW;
    }
  }
  if (currentMillis - previousMillis2 >= interval2) {
    // save the last time you blinked the LED
    previousMillis2 = currentMillis2;
    // if(!block){
    if (State2 == LOW)
    {
      State2 = HIGH;
    }
    else {
      State2 = LOW;
    }
  }
  //}
  if (currentMillis - previousMillis3 >= interval3) {
    // save the last time you blinked the LED
    previousMillis3 = currentMillis;

    // if the LED is off turn it on and vice-versa:
    if (State3 == LOW) {
      State3 = HIGH;
    } else {
      State3 = LOW;
    }
  }
  if (currentMillis - previousMillis4 >= interval4) {
    // save the last time you blinked the LED
    previousMillis4 = currentMillis;

    if (State1 == LOW) {
      State1 = HIGH;
    } else {
      State1 = LOW;
    }
  }
  if (currentMillis - previousMillis5 >= interval5) {
    // save the last time you blinked the LED
    previousMillis5 = currentMillis;
    // if(!block){
    if (State5 == LOW)
    {
      State5 = HIGH;
    }
    else {
      State5 = LOW;
    }
    //}
  }
  digitalWrite(Pin1, State1);
  digitalWrite(Pin2, State2);
  digitalWrite(Pin3, State3);
  digitalWrite(Pin4, State4);
  digitalWrite(Pin5, State5);
  digitalWrite(Pin4, State3);
  if (Serial.available() > 0) { //ÐµÑÐ»Ð¸ ÐµÑÑ‚ÑŒ Ð¿Ñ€Ð¸Ð½ÑÑ‚Ñ‹Ð¹ ÑÐ¸Ð¼Ð²Ð¾Ð»,
    SerialEvent();
  }
}
