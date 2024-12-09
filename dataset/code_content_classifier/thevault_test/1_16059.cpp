void animConfig(
 uint16_t t,   // Time of day in fixed-point 16-bit units, where 0=midnight,
               // 32768=noon, 65536=midnight. THIS DOES NOT CORRESPOND TO
               // ANY SORT OF REAL-WORLD UNITS LIKE SECONDS, nor does it
               // handle things like seasons or Daylight Saving Time, it's
               // just an "ish" approximation to give the sky animation some
               // vague context. The time of day should be polled from the
               // same source that's providing the weather data, DO NOT use
               // millis() or micros() to attempt to follow real time, as
               // the NeoPixel library is known to mangle these interrupt-
               // based functions. TIME OF DAY IS "ISH!"
 uint8_t  c,   // Cloud cover, as a percentage (0-100).
 uint8_t  r,   // Rainfall as a "strength" value (0-255) that doesn't really
               // correspond to anything except "none" to "max."
 uint8_t  s,   // Snowfall, similar "strength" value (0-255).
 uint8_t  l,   // Lightning, ditto.
 uint8_t  w) { // Wind speed as a "strength" value (0-255) that also doesn't
               // correspond to anything real; this is the number of fixed-
               // point units that the clouds will move per frame. There are
               // 65536 units around the 'sky,' so a value of 255 will take
               // about 257 frames to make a full revolution of the LEDs,
               // which at 50 FPS would be a little over 5 seconds.

  timeOfDay          = t;
  cloudCover         = (c > 100) ? 100 : c;
  rainInterval       = r ? map(r, 1, 255, 64, 1) : 0;
  windSpeed          = w;
  lightningIntensity = l;
  snowIntensity      = s;

  // Randomize cloud bitmask based on cloud cover percentage:
  cloudBits = 0;
  for(uint8_t i=0; i<NUM_CLOUD_BITS; i++) {
    cloudBits <<= 1;
    if(cloudCover > random(150)) cloudBits |= 1;
  }

  nFlakes = 0;
  memset(flake, 0, sizeof(flake));
  if(s) {
    uint8_t n = 3 + (snowIntensity * (MAX_FLAKES - 2)) / 256;
    while(nFlakes < n) {
      randomFlake();
    }
  }
}