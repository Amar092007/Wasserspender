#include <Arduino.h>
#include <Bounce2.h>

//this is the main file

#define BTN_YLW 2
#define BTN_BLU 3

#define LED_GRN 8
#define LED_PKN 9

Bounce2 :: Button btnYellow = Bounce2::Button();
Bounce2 :: Button btnBlue = Bounce2::Button();;

int counter = 3;


void setup () {
  Serial.begin(9600);
  pinMode(LED_GRN, OUTPUT);
  pinMode(LED_PKN, OUTPUT);

  btnYellow.attach(BTN_YLW,INPUT_PULLUP);
  btnYellow.setPressedState(LOW);

  btnBlue.attach(BTN_BLU,INPUT_PULLUP);
  btnBlue.setPressedState(LOW);
}
void loop () {
  btnYellow.update();
  btnBlue.update();

  if(btnYellow.pressed()){
    Serial.println("Yellow pressed");
    digitalWrite(LED_GRN,HIGH);
    delay(2000);
    digitalWrite(LED_GRN,LOW);
  }

  if(btnBlue.pressed()){
    Serial.println("Blue pressed");
  }
}
