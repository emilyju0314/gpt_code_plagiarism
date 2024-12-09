Colour Properties::getColour(const std::string& key, unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha)
{
  if (data.count(key) || globals.count(key))
  {
    json val = (*this)[key];
    return Colour(val, red, green, blue, alpha);
  }
  Colour colour = {red, green, blue, alpha};
  return colour;
}