static uchar *calc_mask(uchar *img, int w, int h, Fl_Color bg)
{
  uchar red, green, blue, r, g, b;
  uchar bit, byte, *q;
  Fl::get_color(bg, red, green, blue);
  int W = (w+7)/8; // width of mask
  uchar* mask = new uchar[W * h];
  q = mask;
  while (h-- > 0) { // for each row
    bit = 0x80; // byte with last bit set
    byte = 0; // next mask byte to compute
    for (int j = 0; j < w; j++) { // for each column
      r = *img++; // the pixel color components
      g = *img++;
      b = *img++;
      // if pixel doesn't have bg color, put it in mask
      if (r != red || g != green || b != blue) byte |= bit;
      bit = bit>>1; // shift bit one step to the right
      if (bit == 0) { // single set bit has fallen out
	*q++ = byte; // enter byte in mask
	byte = 0; // reset next mask byte to zero
	bit = 0x80; // and this byte
	}
      }
    if (bit != 0x80) *q++ = byte; // enter last columns' byte in mask
    }
  return mask;
}