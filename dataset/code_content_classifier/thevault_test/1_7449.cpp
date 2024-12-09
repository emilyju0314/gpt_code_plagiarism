void TFT_eSprite::printToSprite(char *cbuffer, uint16_t len) //String string)
{
  if(!this->fontLoaded) return;
  
  //fontFile = SPIFFS.open( this->_gFontFilename, "r" );

  if(!this->fontFile)
  {
    this->fontLoaded = false;
    return;
  }

  uint16_t n = 0;
  bool newSprite = !_created;
  
  if (newSprite)
  {
    int16_t sWidth = 0;
    uint16_t index = 0;

    while (n < len)
    {
      uint16_t unicode = decodeUTF8((uint8_t*)cbuffer, &n, len - n);
      if (this->getUnicodeIndex(unicode, &index))
      {
        if (n == 0) sWidth -= this->gdX[index];
        if (n == len-1) sWidth += ( this->gWidth[index] + this->gdX[index]);
        else sWidth += this->gxAdvance[index];
      }
      else sWidth += this->gFont.spaceWidth + 1;
    }

    createSprite(sWidth, this->gFont.yAdvance);

    if (this->textbgcolor != TFT_BLACK) fillSprite(this->textbgcolor);
  }

  n = 0;

  while (n < len)
  {
    uint16_t unicode = decodeUTF8((uint8_t*)cbuffer, &n, len - n);
    //Serial.print("Decoded Unicode = 0x");Serial.println(unicode,HEX);
    //Serial.print("n = ");Serial.println(n);
    drawGlyph(unicode);
  }

  if (newSprite)
  { // The sprite had to be created so place at TFT cursor
    pushSprite(_tft->cursor_x, _tft->cursor_y);
    deleteSprite();
  }
    
  //fontFile.close();
}