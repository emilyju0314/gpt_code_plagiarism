void _RGBToggle (RGBLED* led) {
   os_intr_lock();                           // disable interrupts
   led->_toggleState();
   os_intr_unlock();                         // enable interrupts
}