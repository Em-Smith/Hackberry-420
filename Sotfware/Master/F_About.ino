/*******************
 * AboutTab
 * This Gives a little information about the creator
 * and purpose of the device.
 */
 void about(){
  tft.setCursor(160, 30);
  tft.setTextColor(HX8357_RED);    tft.setTextSize(6);
  tft.println("ABOUT");

  tft.setCursor(20, 105);
  tft.setTextColor(HX8357_WHITE);    tft.setTextSize(3);
  tft.println("This toy was designed by");
  tft.setCursor(20, 135);
  tft.println("Emily Smith at Hackberry");
  tft.setCursor(20, 165);
  tft.println("Lab. It is meant to be an");
  tft.setCursor(20, 195);
  tft.println("electronic Etch-a-Sketch");

    digitalRead(encoder1But);
  if(digitalRead(encoder1But) == LOW){
    mode = 1;
  }
}
