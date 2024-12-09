void rgbUpdate() {
    int x;
    const uint8_t phaseShift = 10;
    for (x=0; x < ledsPerStrip; x++) {
    int index = (color + x + phaseShift/2) % 180;
    leds.setPixel(x, rainbowColors[index]);
    }
    leds.show();
    color++;
    if(color >= 180) {
    color = 0;
    }
}