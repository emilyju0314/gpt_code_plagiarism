void LED_TFT::setupLCD() {
	// Initial touchscreen and display
	myLCD.InitLCD();
	myLCD.clrScr();
	
	myTouch.begin(WAKE, INTRPT);
	
	pinMode(8, OUTPUT);  //backlight 
	digitalWrite(8, HIGH);//on
  
	
	//Get some default settings;
	strlcpy(currentSetting,"Random Colours", sizeof(currentSetting));
	lightMode = 1;

	//Standard page
	drawLightControl();  // Draws the Home Screen
	//Serial.println("InitLCD");
}