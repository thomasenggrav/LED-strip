#include <Adafruit_NeoPixel.h>
#ifdef _AVR_
#include <avr/power.h>  
#endif

#define PIN_NEO_PIXEL 13
#define NUMPIXELS 32
#define DELAY_INTERVAL 500  

Adafruit_NeoPixel NeoPixel(NUMPIXELS, PIN_NEO_PIXEL, NEO_GRB + NEO_KHZ800);


const int colorPin = 13;
int potPin = A1;
int potVal = 0; 

int hastighet = 0;

int greenColor = 0;
int blueColor = 0;
int redColor = 0;

void randomColorShow(){
  redColor = random(0, 255);
  greenColor = random(0, 255);
  blueColor = random(0, 255);
  for(int i=0; i < NUMPIXELS; i++){
   NeoPixel.setPixelColor(i, NeoPixel.Color(redColor,greenColor,blueColor));
   NeoPixel.show();
   delay(hastighet);
    if (i==NUMPIXELS){
      i=0;
      randomColorShow();
   }
  }
}


void potensiometer(){
  potVal = analogRead(potPin);   // read the potentiometer value at the input pin

  if (potVal < 341)  // Lowest third of the potentiometer's range (0-340)
  {                  
    potVal = (potVal * 3) / 4; // Normalize to 0-255
    hastighet = potVal;
  }
  else if (potVal < 682) // Middle third of potentiometer's range (341-681)
  {
    potVal = ( (potVal-341) * 3) / 4; // Normalize to 0-255
    hastighet = potVal;
  }
  else  // Upper third of potentiometer"s range (682-1023)
  {
    potVal = ( (potVal-683) * 3) / 4; // Normalize to 0-255
    hastighet = potVal;
  }
}

void setup()
{
    Serial.begin(9600);
    pinMode(colorPin, INPUT);
    NeoPixel.begin();
    randomSeed(analogRead(A0));
}

void loop()
{
    Serial.println(potVal);
    potensiometer();
    randomColorShow();
}

