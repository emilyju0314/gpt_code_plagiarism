void RGBLED::setColor(const LEDColor color1, const LEDColor color2,  const LEDColor color3, 
                      const LEDColor color4, const LEDColor color5, const LEDColor color6) {
   _color[0] = color1;           //only arg that must be present
   _color[1] = color2;
   _color[2] = color3;
   _color[3] = color4;
   _color[4] = color5;
   _color[5] = color6;
   _colorIndex = 0;
}