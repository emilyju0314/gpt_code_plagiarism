void RGBLED::setState(const LEDState ledState, const uint32_t interval) {
   if ( _timerArmed ) {
      // reset the timer whenever we change the state
      os_timer_disarm(&_timer);
      _timerArmed = false;
   }
   INFO(F("State set to"), (int)ledState);
   INFO(F("Interval"), interval);
   _state = ledState;
   switch ( ledState ) {
   case LEDState::ON:
   case LEDState::BLINK_ON:
      _illuminated = true;
      _illuminate(_color[0]);

      if ( ledState == LEDState::BLINK_ON ) {
         // blink, with initial state ON - min interval is 5 - see ESP SDK documentation
         os_timer_setfn(&_timer, reinterpret_cast<ETSTimerFunc*>(&_RGBToggle), reinterpret_cast<void*>(this));
         os_timer_arm(&_timer, interval >= 5 ? interval : 5, true);
         _timerArmed = true;
      }
      break;

   case LEDState::OFF:
   case LEDState::BLINK_OFF:
      _illuminated = false;
      _illuminate(LEDColor::NONE);

      if ( ledState == LEDState::BLINK_OFF ) {
         // blinking, but initial state is OFF
         os_timer_setfn(&_timer, reinterpret_cast<ETSTimerFunc*>(&_RGBToggle), reinterpret_cast<void*>(this));
         os_timer_arm(&_timer, interval >= 5 ? interval : 5, true);
         _timerArmed = true;
      }
      break;

   case LEDState::ALTERNATE:
      // alternate between RGB colors
      _illuminated = true;
      _illuminate(_color[0]);
      if ( _color[1] != LEDColor::NONE ) {
         // start alternating with the 2nd color
         _colorIndex = 1;
      }
      os_timer_setfn(&_timer, reinterpret_cast<ETSTimerFunc*>(&_RGBAlternate), reinterpret_cast<void*>(this));
      os_timer_arm(&_timer, interval >= 5 ? interval : 5, true);
      _timerArmed = true;
      break;

   default:
      break;
   }
}