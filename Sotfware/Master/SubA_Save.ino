/****************************************
 * SaveTab
 * here lies the save tab
 * beloved mother and husband
 * will always be loved
 * 
 

void save() {
  tft.setTextColor(HX8357_WHITE);    tft.setTextSize(5);
  tft.setCursor(85, 20);
  tft.println("Save Screen");
  tft.setCursor(120, 120);
  tft.setTextSize(4);
  tft.println("SAVE");
  tft.setCursor(240, 120);
  tft.println("QUIT");

  tft.drawRect(saveRectX, 116, 100, 35, HX8357_WHITE);


  n0 = digitalRead(encoder0PinA);
  if ((encoder0PinALast == LOW) && (n0 == HIGH)) {
    if (digitalRead(encoder0PinB) == LOW) {
      encoder0Pos--;
      
    } else {
      encoder0Pos++;
      saveRectX = saveRectX + 120;
      tft.drawRect(saveRectX - 120, 116, 100, 35, HX8357_BLACK);
      //   delay(50);
    }
    if (saveRectX > 340) {
      saveRectX = 118;
    }
  }
  if(digitalRead(encoder1But) == LOW && (saveRectX = 238)){
    mode=1;
  }
  //below changed to save image
   if(digitalRead(encoder1But) == LOW && (saveRectX = 118)){
    mode=1;
  } 
  Serial.print (encoder0Pos);
  Serial.print ("/");
  encoder0PinALast = n0;
}*/
