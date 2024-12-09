inline void Yuv2Rgb(uint8_t y_value, uint8_t u_value, uint8_t v_value,
                    uint8_t* r, uint8_t* g, uint8_t* b) {
  float float_r = y_value + (1.370705 * (v_value - 128));
  float float_g =
      y_value - (0.698001 * (v_value - 128)) - (0.337633 * (u_value - 128));
  float float_b = y_value + (1.732446 * (u_value - 128));

  float_r = float_r * !(float_r < 0);
  float_g = float_g * !(float_g < 0);
  float_b = float_b * !(float_b < 0);

  *r = float_r * (!(float_r > 255)) + 255 * (float_r > 255);
  *g = float_g * (!(float_g > 255)) + 255 * (float_g > 255);
  *b = float_b * (!(float_b > 255)) + 255 * (float_b > 255);
}