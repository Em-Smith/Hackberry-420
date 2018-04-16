/********************************
 * HelpTab
 * provides instructions that
 * supplies absolutely no help
 * good luck
 */
 
 void help(){
  tft.setCursor(185, 10);
  tft.setTextColor(HX8357_RED);    tft.setTextSize(6);
  tft.println("Help");
  tft.setCursor(143, 55);
  tft.println("Screen");
  tft.println();

  tft.setCursor(30, 120);
  tft.setTextColor(HX8357_WHITE);    tft.setTextSize(4);
  tft.println("Use dials to draw.");
  tft.setCursor(30, 160);
  tft.println("To select options");
  tft.setCursor(30, 200);
  tft.println("push dials.");
  
    digitalRead(encoder1But);
  if(digitalRead(encoder1But) == LOW){
    mode = 1;
  }
}
