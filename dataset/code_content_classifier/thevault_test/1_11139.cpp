static void ComputeGradient(const l_uint32 *data, int wpl, int x, int y, int width, int height,
                            ICOORD *gradient) {
  const l_uint32 *line = data + y * wpl;
  int pix_x_y = x < width && y < height ? GET_DATA_BYTE(line, x) : 255;
  int pix_x_prevy = x < width && y > 0 ? GET_DATA_BYTE(line - wpl, x) : 255;
  int pix_prevx_prevy = x > 0 && y > 0 ? GET_DATA_BYTE(line - wpl, x - 1) : 255;
  int pix_prevx_y = x > 0 && y < height ? GET_DATA_BYTE(line, x - 1) : 255;
  gradient->set_x(pix_x_y + pix_x_prevy - (pix_prevx_y + pix_prevx_prevy));
  gradient->set_y(pix_x_prevy + pix_prevx_prevy - (pix_x_y + pix_prevx_y));
}