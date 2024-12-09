void TFT_eSprite::drawGlyph(uint16_t code)
{
  if (code < 0x21)
  {
    if (code == 0x20) {
      if (_created) this->cursor_x += this->gFont.spaceWidth;
      else this->cursor_x += this->gFont.spaceWidth;
      return;
    }

    if (code == '\n') {
      if (_created)
      {
        this->cursor_x = 0;
        this->cursor_y += this->gFont.yAdvance;
        if (this->cursor_y >= _height) this->cursor_y = 0;
        return;
      }
      else
      {
        cursor_x = 0;
        cursor_y += gFont.yAdvance;
        if (cursor_y >= _height) cursor_y = 0;
        return;
      }
    }
  }

  uint16_t gNum = 0;
  bool found = this->getUnicodeIndex(code, &gNum);
  
  uint16_t fg = this->textcolor;
  uint16_t bg = this->textbgcolor;

  if (found)
  {
    
    bool newSprite = !_created;
  
    if (newSprite)
    {
      createSprite(this->gWidth[gNum], this->gFont.yAdvance);
      if(bg) fillSprite(bg);
      this->cursor_x = -this->gdX[gNum];
      this->cursor_y = 0;
    }

    this->fontFile.seek(this->gBitmap[gNum], fs::SeekSet); // This is slow for a significant position shift!

    uint8_t pbuffer[this->gWidth[gNum]];

    int16_t  xs = 0;
    uint16_t dl = 0;

    for (int32_t y = 0; y < this->gHeight[gNum]; y++)
    {
      this->fontFile.read(pbuffer, this->gWidth[gNum]);
      for (int32_t x = 0; x < this->gWidth[gNum]; x++)
      {
        uint8_t pixel = pbuffer[x];
        if (pixel)
        {
          if (pixel != 0xFF)
          {
            if (dl) { drawFastHLine( xs, y + this->cursor_y + this->gFont.maxAscent - this->gdY[gNum], dl, fg); dl = 0; }
            if (_bpp != 1) drawPixel(x + this->cursor_x + this->gdX[gNum], y + this->cursor_y + this->gFont.maxAscent - this->gdY[gNum], alphaBlend(pixel, fg, bg));
            else if (pixel>127) drawPixel(x + this->cursor_x + this->gdX[gNum], y + this->cursor_y + this->gFont.maxAscent - this->gdY[gNum], fg);
          }
          else
          {
            if (dl==0) xs = x + this->cursor_x + this->gdX[gNum];
            dl++;
          }
        }
        else
        {
          if (dl) { drawFastHLine( xs, y + this->cursor_y + this->gFont.maxAscent - this->gdY[gNum], dl, fg); dl = 0; }
        }
      }
      if (dl) { drawFastHLine( xs, y + this->cursor_y + this->gFont.maxAscent - this->gdY[gNum], dl, fg); dl = 0; }
    }

    if (newSprite)
    {
      pushSprite(this->cursor_x + this->gdX[gNum], this->cursor_y, bg);
      deleteSprite();
      this->cursor_x += this->gxAdvance[gNum];
    }
    else this->cursor_x += this->gxAdvance[gNum];
  }
  else
  {
    // Not a Unicode in font so draw a rectangle and move on cursor
    drawRect(this->cursor_x, this->cursor_y + this->gFont.maxAscent - this->gFont.ascent, this->gFont.spaceWidth, this->gFont.ascent, fg);
    this->cursor_x += this->gFont.spaceWidth + 1;
  }
}