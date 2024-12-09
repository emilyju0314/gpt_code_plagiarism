uint16_t Adafruit_MPR121_mod::filteredDataAveraged(uint8_t t, uint8_t n) {
  uint16_t avg = 0;
  uint16_t n2 = 1 << n;
  for (uint8_t i = 0; i < n2; i++) {
    avg += filteredData(t);
  }
  avg = avg >> n;
  return avg;
}