void ui_obj::draw_bmp(uint8_t x1, uint16_t y1)
{
  //uint16_t w, h;
  uint16_t tft_width  = TFT_WIDTH;
  uint16_t tft_height = TFT_HEIGHT;
  if ((x1 >= tft_width) || (y1 >= tft_height)) return;

#ifdef BMP_FROM_SPIFFS
  File fp = open_palette_file(bmp_filename[state]);
  if (!fp)
    return;
  read_bmp_spiffs(fp, 1, &w);
  read_bmp_spiffs(fp, 1, &h);
#else
  bmp_cnt = 0;
  // First 4 bytes gives height and width
  w = read_bmp_progmem();
  h = read_bmp_progmem();
#endif

  // Crop area to be loaded
  //if ((x1 + w - 1) >= tft_width)  w = tft_width  - x1;
  //if ((y1 + h - 1) >= tft_height) h = tft_height - y1;

  // Set TFT address window to clipped image bounds
  tft_start_write();
  tft_set_addr_window(x1, y1, w, h);

  uint32_t pixel_cnt = w * h, read_cnt = 0;

#ifndef BMP_FROM_SPIFFS
  for ( ; read_cnt < pixel_cnt; read_cnt++)
	  tft_write_pixel(read_bmp_progmem());
#else
  read_cnt = (pixel_cnt < SPIFFS_DEF_READ_CNT) ? pixel_cnt : SPIFFS_DEF_READ_CNT;
  uint16_t palette[read_cnt];

  while (pixel_cnt)
  {
	read_bmp_spiffs(fp, read_cnt, palette);

	tft_write_pixels(palette, read_cnt);

    pixel_cnt -= read_cnt;
    if (pixel_cnt < read_cnt)
      read_cnt = pixel_cnt;
  }

  close_palette_file(fp);
#endif

  tft_end_write();
}