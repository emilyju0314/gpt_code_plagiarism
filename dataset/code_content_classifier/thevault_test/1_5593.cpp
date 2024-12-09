void
InitCrop()
{
#ifdef USE_CROP_TABLE
  int i;

  /* Initialize crop table. */
  for (i = (-MAX_NEG_CROP); i < NUM_CROP_ENTRIES - MAX_NEG_CROP; i++) {
    if (i <= 0) {
      cropTbl[i + MAX_NEG_CROP] = 0;
#ifdef TWELVE_BITS
        } else if (i >= 2047) {
      cropTbl[i + MAX_NEG_CROP] = 2047;
#endif
    } else if (i >= 255) {
      cropTbl[i + MAX_NEG_CROP] = 255;
    } else {
      cropTbl[i + MAX_NEG_CROP] = i;
    }
  }
#endif /* USE_CROP_TABLE */
}