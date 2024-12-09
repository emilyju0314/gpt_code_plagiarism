void animSetup(void) {

  leds.begin();
  leds.setBrightness(200);
  leds.clear(); // All NeoPixels off ASAP
  leds.show();

  randomSeed(analogRead(A0));

  memset(rainBuf, 0, sizeof(rainBuf)); // Clear rain buffer
  for(uint8_t i=0; i<N_STARS; i++) {   // Initialize star positions
    star[i].pos = random(NUM_LEDS);    // TO DO: make stars not overlap
    star[i].brightness = random(15, 45);
  }
  memset(flake, 0, sizeof(flake));     // Clear snowflakes
}