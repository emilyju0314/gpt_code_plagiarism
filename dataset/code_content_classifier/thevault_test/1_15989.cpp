void RGBLED::_alternateRGB(void) {
   _illuminate(_color[_colorIndex]);
   // display next color until we get LEDColor::NONE or reach the end
   if ( (_colorIndex < (MAX_RGB_COLORS-1)) && (_color[_colorIndex+1] != LEDColor::NONE) ) {
      ++_colorIndex;
   } else {
      // cycle back to the start
      _colorIndex = 0; 
   }
}