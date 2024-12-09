void user_setup(void) {
  // follow the WiiAccessory.ino example:
  nunchuck1.begin();
  if(nunchuck1.type == Unknown) {
    /** If the device isn't auto-detected, set the type explicitly:
      NUNCHUCK,
      WIICLASSIC,
      GuitarHeroController,
      GuitarHeroWorldTourDrums,
      DrumController,
      DrawsomeTablet,
      Turntable
    */
    nunchuck1.type = NUNCHUCK;
  }
}