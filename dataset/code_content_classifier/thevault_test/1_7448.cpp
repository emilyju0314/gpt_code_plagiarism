void TFT_eSprite::printToSprite(String string)
{
  if(!this->fontLoaded) return;
  uint16_t len = string.length();
  char cbuffer[len + 1];              // Add 1 for the null
  string.toCharArray(cbuffer, len + 1); // Add 1 for the null, otherwise characters get dropped
  printToSprite(cbuffer, len);
  //printToSprite((char*)string.c_str(), string.length());
}