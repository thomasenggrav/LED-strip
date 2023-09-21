#include <Adafruit_NeoPixel.h>
#ifdef _AVR_
#include <avr/power.h>  
#endif

#define PIN_NEO_PIXEL 13
#define NUMPIXELS 32
#define DELAY_INTERVAL 500  

Adafruit_NeoPixel NeoPixel(NUMPIXELS, PIN_NEO_PIXEL, NEO_GRB + NEO_KHZ800);

const int colorPin = 13;
int redPotPin = A1;
int redPotVal = 0; 

int greenPotPin = A2;
int greenPotVal = 0; 

int bluePotPin = A3;
int bluePotVal = 0; 

int redColor = 0;
int greenColor = 0;
int blueColor = 0;



void redPotensiometer(){
  redPotVal = analogRead(redPotPin);   // read the potentiometer value at the input pin

  if (redPotVal < 341)  // Lowest third of the potentiometer's range (0-340)
  {                  
    redPotVal = (redPotVal * 3) / 4; // Normalize to 0-255
    redColor = redPotVal;
  }
  else if (redPotVal < 682) // Middle third of potentiometer's range (341-681)
  {
    redPotVal = ( (redPotVal-341) * 3) / 4; // Normalize to 0-255
    redColor = redPotVal;
  }
  else  // Upper third of potentiometer"s range (682-1023)
  {
    redPotVal = ( (redPotVal-683) * 3) / 4; // Normalize to 0-255
    redColor = redPotVal;
  }
}

void greenPotensiometer(){
  greenPotVal = analogRead(greenPotPin);   // read the potentiometer value at the input pin

  if (greenPotVal < 341)  // Lowest third of the potentiometer's range (0-340)
  {                  
    greenPotVal = (greenPotVal * 3) / 4; // Normalize to 0-255
    greenColor = greenPotVal;
  }
  else if (greenPotVal < 682) // Middle third of potentiometer's range (341-681)
  {
    greenPotVal = ( (greenPotVal-341) * 3) / 4; // Normalize to 0-255
    greenColor = greenPotVal;
  }
  else  // Upper third of potentiometer"s range (682-1023)
  {
    greenPotVal = ( (greenPotVal-683) * 3) / 4; // Normalize to 0-255
    greenColor = greenPotVal;
  }
}

void bluePotensiometer(){
  bluePotVal = analogRead(bluePotPin);   // read the potentiometer value at the input pin

  if (bluePotVal < 341)  // Lowest third of the potentiometer's range (0-340)
  {                  
    bluePotVal = (bluePotVal * 3) / 4; // Normalize to 0-255
    blueColor = bluePotVal;
  }
  else if (bluePotVal < 682) // Middle third of potentiometer's range (341-681)
  {
    bluePotVal = ( (bluePotVal-341) * 3) / 4; // Normalize to 0-255
    blueColor = bluePotVal;
  }
  else  // Upper third of potentiometer"s range (682-1023)
  {
    bluePotVal = ( (bluePotVal-683) * 3) / 4; // Normalize to 0-255
    blueColor = bluePotVal;
  }
}

void visFarge()
{
    for(int i=0; i < NUMPIXELS; i++){
    NeoPixel.setPixelColor(i, NeoPixel.Color(redColor,greenColor,blueColor));
    NeoPixel.show();
    delay(100);
    if (i==NUMPIXELS){
      i=0;
      visFarge();
   }
  }
}

void setup()
{
    Serial.begin(9600);
    pinMode(colorPin, INPUT);
    NeoPixel.begin();
}

void loop()
{
    redPotensiometer();
    greenPotensiometer();
    bluePotensiometer();
    visFarge();
}