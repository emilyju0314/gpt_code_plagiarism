int Convert::base40IntervalToDiatonic(int base40interval) {
   int sign = 1;
   if (base40interval < 0) {
      sign = -1;
      base40interval = -base40interval;
   }
   int octave = base40interval / 40;
   base40interval = base40interval % 40;

   int diatonic = 0;
   switch (base40interval) {
      case  0: diatonic = 0; break;  // C
      case  1: diatonic = 0; break;  // C#
      case  2: diatonic = 0; break;  // C##

      case  3: diatonic = 1000; break;  // blank

      case  4: diatonic = 1; break;  // D--
      case  5: diatonic = 1; break;  // D-
      case  6: diatonic = 1; break;  // D
      case  7: diatonic = 1; break;  // D#
      case  8: diatonic = 1; break;  // D##

      case  9: diatonic = 1000; break;  // blank

      case 10: diatonic = 2; break;  // E--
      case 11: diatonic = 2; break;  // E-
      case 12: diatonic = 2; break;  // E
      case 13: diatonic = 2; break;  // E#
      case 14: diatonic = 2; break;  // E##

      case 15: diatonic = 3; break;  // F--
      case 16: diatonic = 3; break;  // F-
      case 17: diatonic = 3; break;  // F
      case 18: diatonic = 3; break;  // F#
      case 19: diatonic = 3; break;  // F##

      case 20: diatonic = 1000; break;  // blank

      case 21: diatonic = 4; break;  // G--
      case 22: diatonic = 4; break;  // G-
      case 23: diatonic = 4; break;  // G
      case 24: diatonic = 4; break;  // G#
      case 25: diatonic = 4; break;  // G##

      case 26: diatonic = 1000; break;  // blank

      case 27: diatonic = 5; break;  // A--
      case 28: diatonic = 5; break;  // A-
      case 29: diatonic = 5; break;  // A
      case 30: diatonic = 5; break;  // A#
      case 31: diatonic = 5; break;  // A##

      case 32: diatonic = 1000; break;  // blank

      case 33: diatonic = 6; break;  // B--
      case 34: diatonic = 6; break;  // B-
      case 35: diatonic = 6; break;  // B
      case 36: diatonic = 6; break;  // B#
      case 37: diatonic = 6; break;  // B##

      case 38: diatonic = 0; break;  // C--
      case 39: diatonic = 0; break;  // C-
   }

   return sign * (diatonic + octave * 7);
}