void user_setup(StaticJsonDocument<2048> &doc) {
  low = getDocInt(doc, "wiichuck", "min", 0);
  high = getDocInt(doc, "wiichuck", "max", 255);
  divFactor = (high - low) / 3 + 1;
  Serial.println("user_setup(doc)");

  const char *neopin = doc["wiichuck"]["neopixel"]["pin"];
  Serial.println("neopin=" + String(neopin ? neopin : "(null)"));
  int32_t neomax = getDocInt(doc, "wiichuck", "neopixel", "max", -1);
  Serial.println("neopin=" + String(neomax));

  if(neopin && neomax > -1) {
    if((strcmp(neopin, "d2") == 0) || (strcmp(neopin, "D2") == 0))
      neoPixelPin = 2;
    else if((strcmp(neopin, "d3") == 0) || (strcmp(neopin, "D3") == 0))
      neoPixelPin = 3;
    neoPixelMax = neomax;

    strip.setPin(neoPixelPin);
    strip.updateLength(neoPixelMax);
    strip.updateType(NEO_GRB + NEO_KHZ800);
    strip.setBrightness(50); // Set BRIGHTNESS to about 1/5 (max = 255)
    strip.show();            // Turn OFF all pixels ASAP
    strip.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  }    
}