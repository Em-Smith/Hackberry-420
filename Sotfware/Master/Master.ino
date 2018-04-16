/*GRAND MASTER TAB
 * holds all basic code contained in setup and loop
 * without the master nothing would work 
 * we would simply be wandering beings in a sea of confusion
 * chaos would insue
 * and we would die, die free
 * but die none the less
 */
 
#include <SPI.h>
#include <SD.h>
#include "Adafruit_GFX.h"
#include "Adafruit_HX8357.h"

// These are 'flexible' lines that can be changed
#define TFT_CS 10
#define TFT_DC 9
#define TFT_RST 8 // RST can be set to -1 if you tie it to Arduino's reset
#define SD_CS 4
#define GREY 0x0009

//encoder0
int val;
int encoder0PinA = 2;
int encoder0PinB = 3;
int encoder0But = 5;
int encoder0Pos = 0;
int encoder0PinALast = LOW;
int n0 = LOW;
int TrackPos0 = 0;

int mode = 0;
int col = 0;
int previousMode = 0;

//encoder1
int encoder1PinA = 6;
int encoder1PinB = 7;
int encoder1But = 8;
int encoder1Pos = 0;
int encoder1PinALast = LOW;
int n1 = LOW;

int x = 50;
int y = 50;
int rectY = 120;
int saveRectX = 116;
int blackRectX = 0;
int multX= 163;
int multY= 230;
int currentX;
int currentY;


boolean ifPressed = false;
boolean screenFill = false;
boolean mazeLoaded = false;


// Use hardware SPI (on Uno, #13, #12, #11) and the above for CS/DC
Adafruit_HX8357 tft = Adafruit_HX8357(TFT_CS, TFT_DC, TFT_RST);
void setup() {
  pinMode (encoder0PinA, INPUT);
  pinMode (encoder0PinB, INPUT);
  pinMode (encoder0But, INPUT);

  pinMode (encoder1PinA, INPUT);
  pinMode (encoder1PinB, INPUT);
  pinMode (encoder1But, INPUT);

  Serial.begin (9600);
  Serial.println("HX8357D Test!");

  tft.begin(HX8357D);

    Serial.print("Initializing SD card...");
    if (!SD.begin(SD_CS)) {
    Serial.println("failed!");
  }
  Serial.println("OK!");


  // read diagnostics (optional but can help debug problems)
  uint8_t x = tft.readcommand8(HX8357_RDPOWMODE);
  Serial.print("Display Power Mode: 0x"); Serial.println(x, HEX);
  x = tft.readcommand8(HX8357_RDMADCTL);
  Serial.print("MADCTL Mode: 0x"); Serial.println(x, HEX);
  x = tft.readcommand8(HX8357_RDCOLMOD);
  Serial.print("Pixel Format: 0x"); Serial.println(x, HEX);
  x = tft.readcommand8(HX8357_RDDIM);
  Serial.print("Image Format: 0x"); Serial.println(x, HEX);
  x = tft.readcommand8(HX8357_RDDSDR);
  Serial.print("Self Diagnostic: 0x"); Serial.println(x, HEX);

  Serial.println(F("Benchmark                Time (microseconds)"));

  tft.setRotation(1);
  tft.fillScreen(HX8357_BLACK);

}



void loop() {
  switch(mode){
    case 0: splashScreen();
      break;
    case 1: menuSelect();
      break;
    case 2: sketchMode();
      break;
    case 3: maze();
      break;
    case 4: egg();
      break;
    case 5: about();
      break;
    case 6: help();
      break;
    case 7: gallery();
      break;

  }
    if(previousMode != mode){
    tft.fillScreen(HX8357_BLACK);
    previousMode = mode;
    mazeLoaded = false;
  }
}





