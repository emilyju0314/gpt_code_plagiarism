void overlay(uint8_t r, uint8_t g, uint8_t b) {
  uint16_t i, a1, a2;
  for(i=0; i<NUM_LEDS; i++) {
    a1 = alphaBuf[i] + 1; // 1-256
    a2 = 257 - a1;        // 1-256
    renderBuf[i][0] = (r * a1 + renderBuf[i][0] * a2) >> 8;
    renderBuf[i][1] = (g * a1 + renderBuf[i][1] * a2) >> 8;
    renderBuf[i][2] = (b * a1 + renderBuf[i][2] * a2) >> 8;
  }
}