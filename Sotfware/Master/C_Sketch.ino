/*************************************
 * SketchModeTab
 * EtchaSketch drawing screen
 * 
 */
 
void sketchMode() {
  //Easter Egg PIXEL
  tft.drawPixel(350, 50, GREY);

  //Drawing Pixel and Color Changer
  switch (col){
    case 0: tft.drawPixel(x, y, HX8357_CYAN);
      break;
    case 1: tft.drawPixel(x, y, HX8357_YELLOW);
      break;
    case 2: tft.drawPixel(x, y, HX8357_GREEN);
      break;
    case 3: tft.drawPixel(x, y, HX8357_MAGENTA); 
      break;
    case 4: tft.drawPixel(x, y, HX8357_RED);
      break;
    case 5: tft.drawPixel(x, y, HX8357_WHITE);
      break;
  }
  //If draw pixel = easter pixel switch to egg mode
  if((x == 350) && (y == 50)){
    mode = 4;
  }
  if(y < 1){
    y = 1;
  }
  if(y> 318){
    y = 318;
  }
  if(x<1){
    x = 1;
  }
  if(x>478){
    x = 478;
  }
  
  
  //encoder0 = left
  n0 = digitalRead(encoder0PinA);
  if ((encoder0PinALast == LOW) && (n0 == HIGH)) {
    if (digitalRead(encoder0PinB) == LOW) {
      encoder0Pos--;
      x = x - 1;
    } else {
      encoder0Pos++;
      x = x + 1;     
    }
    Serial.print (encoder0Pos);
    Serial.print ("/");
  }
  encoder0PinALast = n0;

  //encoder1 = right
  n1 = digitalRead(encoder1PinA);
  if ((encoder1PinALast == LOW) && (n1 == HIGH)) {
    if (digitalRead(encoder1PinB) == LOW) {
      encoder1Pos--;
      y = y + 1;
    } else {
      encoder1Pos++;
      y = y - 1;
    }
    Serial.print (encoder1Pos);
    Serial.print ("/");
  }
  encoder1PinALast = n1;

  if(digitalRead(encoder1But) ==LOW){
    mode = 1;
    x = 50;
    y = 50;
  }
  digitalRead(encoder0But);
  if(digitalRead(encoder0But) == LOW){
    col = (col + 1) % 6;
    delay(250);
  }
}

