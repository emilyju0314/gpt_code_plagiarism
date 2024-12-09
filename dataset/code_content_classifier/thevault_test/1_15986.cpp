void _RGBAlternate (RGBLED* led) {
   os_intr_lock();
   led->_alternateRGB();
   os_intr_unlock();
}