/**********************************
 * MenuSelect Tab
 * this controls the selection of menu items on the main
 * menu page
 */
 
 void menuSelect(){
  //calls main menu and selection box draw
   mainMenu();
   tft.drawRect( 26, rectY, 240, 30, HX8357_WHITE);
  //encoder1

  //left encoder spin to move box up and down
  
    n0 = digitalRead(encoder0PinA);
  if ((encoder0PinALast == LOW) && (n0 == HIGH)) {
    if (digitalRead(encoder0PinB) == LOW) {
      encoder0Pos--;

    } else {
      encoder0Pos++;
      rectY = rectY + 30;
      tft.drawRect(26, rectY-30, 240, 30, HX8357_BLACK);
      delay(50);
    }
     if(rectY >= 270){
     rectY= 120;
     }
    Serial.print (encoder0Pos);
    Serial.print ("/");
  }
  encoder0PinALast = n0;


  //right encoder clicked means that the item is selected
  
  digitalRead(encoder1But);
  if(digitalRead(encoder1But) == LOW && (rectY == 120)){
    ifPressed = !ifPressed;
  }
  if(ifPressed == true){
    mode = 2;
    ifPressed = false;
  }

  if(digitalRead(encoder1But) == LOW && (rectY == 150)){
    ifPressed = !ifPressed;
  }
  if(ifPressed == true){
    mode = 7;
    ifPressed = false;
  }
  if(digitalRead(encoder1But) == LOW && (rectY == 180)){
    ifPressed = !ifPressed;
  }
  if(ifPressed == true){
    mode = 3;
    ifPressed = false;
  }
  if(digitalRead(encoder1But) == LOW && (rectY == 210)){
    ifPressed = !ifPressed;
  }
  if(ifPressed == true){
    mode = 5;
    ifPressed = false;
  }
    if(digitalRead(encoder1But) == LOW && (rectY == 240)){
    ifPressed = !ifPressed;
  }
  if(ifPressed == true){
    mode = 6;
    ifPressed = false;
  }
 }
