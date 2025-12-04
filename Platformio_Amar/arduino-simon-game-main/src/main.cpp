#include <Arduino.h>
#include <Bounce2.h>

//this is the main file

#define BTN_YLW 2
#define BTN_BLU 3

#define LED_GRN 8
#define LED_PKN 9

Bounce2 :: Button btnYellow = Bounce2::Button();
Bounce2 :: Button btnBlue = Bounce2::Button();;


int counter = 5;


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
    for(int i = 1; i <= 3;i++){
      digitalWrite(LED_PKN,HIGH);
      delay(200);
      digitalWrite(LED_PKN,LOW);
      delay(200);

    }

    for(int i = 1; i <= 3;i++){
      digitalWrite(LED_PKN,HIGH);
      delay(1000);
      digitalWrite(LED_PKN,LOW);
      delay(1000);

    }

    for(int i = 1; i <= 3;i++){
      digitalWrite(LED_PKN,HIGH);
      delay(200);
      digitalWrite(LED_PKN,LOW);
      delay(200);

    }
  }

   if(btnBlue.pressed()){
    Serial.println("Blue pressed");

    for(int i = 0; i < 10; i++){   // 10x wechseln
      // ROSA / ROT
      digitalWrite(LED_PKN, HIGH);
      digitalWrite(LED_GRN, LOW);
      delay(500);

      // GRÜN
      digitalWrite(LED_PKN, LOW);
      digitalWrite(LED_GRN, HIGH);
      delay(500);
    }

    // Am Ende alles ausschalten
    digitalWrite(LED_PKN, LOW);
    digitalWrite(LED_GRN, LOW);
  }

}
