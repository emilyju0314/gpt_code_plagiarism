int16_t TFT_eSprite::printToSprite(int16_t x, int16_t y, uint16_t index)
{
  bool newSprite = !_created;
  int16_t sWidth = this->gWidth[index];

  if (newSprite)
  {
    createSprite(sWidth, this->gFont.yAdvance);

    if (this->textbgcolor != TFT_BLACK) fillSprite(this->textbgcolor);

    drawGlyph(this->gUnicode[index]);

    pushSprite(x + this->gdX[index], y, this->textbgcolor);
    deleteSprite();
  }

  else drawGlyph(this->gUnicode[index]);

  return this->gxAdvance[index];
}