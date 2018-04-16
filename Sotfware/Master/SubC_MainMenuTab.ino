 /*Main Menu Display
  * Called in menuselect
  * writes out menu stuff
  */
 void mainMenu() {
  tft.setTextColor(HX8357_RED);    tft.setTextSize(6);
  tft.setCursor(185, 15);
  tft.println("Main");
  tft.setCursor(185, 65);
  tft.println("Menu");
  tft.println();
  tft.setCursor(30, 125);
  tft.setTextColor(HX8357_WHITE);    tft.setTextSize(3);
  tft.println("SKETCHY MODE");
  tft.setCursor(30, 155);
  tft.println("GALLERY-OUS");
  tft.setCursor(30, 185);
  tft.println("A-MAZE ME");
  tft.setCursor(30, 215);
  tft.println("ABOUT");
  tft.setCursor(30, 245);
  tft.println("HELP");

//  tft.setCursor(100, 20);
 // tft.drawRect( 26, rectY, 240, 30, HX8357_WHITE);
}
