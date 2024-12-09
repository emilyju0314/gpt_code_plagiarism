string Convert::durationFloatToRecip(double input, HumNum timebase) {
	string output;

   double testinput = input;
   double basic = 4.0 / input * timebase.getFloat();
   double diff = basic - (int)basic;

   if (diff > 0.998) {
      diff = 1.0 - diff;
      basic += diff;
   }

	// do power of two checks instead
   if (input == 0.0625)  { output = "64"; return output; }
   if (input == 0.125)   { output = "32"; return output; }
   if (input == 0.25)    { output = "16"; return output; }
   if (input == 0.5)  { output = "8";    return output; }
   if (input == 1.0)  { output = "4";    return output; }
   if (input == 2.0)  { output = "2";    return output; }
   if (input == 4.0)  { output = "1";    return output; }
   if (input == 8.0)  { output = "0";    return output; }
   if (input == 12.0) { output = "0.";   return output; }
   if (input == 16.0) { output = "00";   return output; }
   if (input == 24.0) { output = "00.";  return output; }
   if (input == 32.0) { output = "000";  return output; }
   if (input == 48.0) { output = "000."; return output; }

   // special case for triplet whole notes:
   if (fabs(input - (4.0 * 2.0 / 3.0)) < 0.0001) {
		return "3%2";
   }

   // special case for triplet breve notes:
   if (fabs(input - (4.0 * 4.0 / 3.0)) < 0.0001) {
		return "3%4";
   }

   // special case for 9/8 full rests
   if (fabs(input - (4.0 * 9.0 / 8.0)) < 0.0001) {
		return "8%9";
   }

   // special case for 9/2 full-measure rest
   if (fabs(input - 18.0) < 0.0001) {
		return "2%9";
   }

   // handle special rounding cases primarily for SCORE which
   // only stores 4 digits for a duration
   if (input == 0.0833) {
      // triplet 32nd note, which has a real duration of 0.0833333 etc.
		return "48";
   }

   if (diff < 0.002) {
		output += to_string((int)basic);
   } else {
      testinput = input / 3.0 * 2.0;
      basic = 4.0 / testinput;
      diff = basic - (int)basic;
      if (diff < 0.002) {
			output += to_string((int)basic);
			output += ".";
      } else {
         testinput = input / 7.0 * 4.0;
         basic = 4.0 / testinput;
         diff = basic - (int)basic;
         if (diff < 0.002) {
				output += to_string((int)basic);
            output += "..";
         } else {
            testinput = input / 15.0 * 4.0;
            basic = 2.0 / testinput;
            diff = basic - (int)basic;
            if (diff < 0.002) {
					output += to_string((int)basic);
               output += "...";
            } else {
					// Don't know what it could be so echo as a grace note.
					output += "q";
					output += to_string(input);
            }
         }
      }
   }

   return output;
}