#include <Arduino.h>

int conuter = 0;


void setup() 
{
  Serial.begin(9600);
}
void loop()
{
  conuter++;
  if(conuter %3 == 0)
  {
    if (conuter % 5 == 0)
    {
      Serial.println(" fizz Buzz");
    }
    else{
      Serial.println("Buzz");
    }

  }
  else{
    if (conuter %5 ==0)
    {
      Serial.println("Buzz");
    }
    else{
      Serial.println(conuter);
    }
    

  }
  
  delay(500);
}
