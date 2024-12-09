void RGBLED::_toggleState (void) {
   if ( _illuminated ) {
      _illuminated = false;
      _illuminate(LEDColor::NONE);
   } else {
      _illuminated = true;
      _illuminate(_color[0]);
   }
}