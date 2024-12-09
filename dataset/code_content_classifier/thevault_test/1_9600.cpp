int MuseRecord::getAddElementIndex(int& index, string& output, const string& input) {
	int finished = 0;
	int count = 0;
	output.clear();

	while (!finished) {
		switch (input[index]) {
			case '&':                     // editorial level marker
				// there is exactly one character following an editorial
				// marker.  neither the '&' nor the following character
				// is counted if the following character is in the set
				// [0..9, A..Z, a..z]
				index++;
				if (isalnum(input[index])) {
					index++;
				} else {
					// count '&' as an element
					count++;
					output += '&';
				}
				break;

			case 'p': case 'f':          // piano and forte
				// any sequence of 'p' and 'f' is considered one element
				count++;
				output += input[index++];
				while (input[index] == 'p' || input[index] == 'f') {
					output += input[index++];
				}
				break;

			case 'Z':                    // sfz, or Zp = sfp
				// elements starting with 'Z':
				//    Z      = sfz
				//    Zp     = sfp
				count++;
				output += input[index++];
				if (input[index] == 'p') {
					output += input[index++];
				}
				break;

			case 'm':                      // mezzo
				// a mezzo marking MUST be followed by a 'p' or an 'f'.
				count++;
				output += input[index++];
				if (input[index] == 'p' || input[index] == 'f') {
					output += input[index++];
				} else {
				  cout << "Error at \'m\' in notation field: " << input << endl;
				  return 0;
				}
				break;

			case 'S':                     // arpeggiation
				// elements starting with 'S':
				//   S     = arpeggiate (up)
				//   Sd    = arpeggiate down)
				count++;
				output += input[index++];
				if (input[index] == 'd') {
					output += input[index++];
				}
				break;

			case '1':                     // fingering
			case '2':                     // fingering
			case '3':                     // fingering
			case '4':                     // fingering
			case '5':                     // fingering
			// case ':':                  // finger substitution
				// keep track of finger substitutions
				count++;
				output += input[index++];
				if (input[index] == ':') {
					output += input[index++];
					output += input[index++];
				}
				break;

			//////////////////////////////
			// Ornaments
			//
			case 't':                     // trill (tr.)
			case 'r':                     // turn
			case 'k':                     // delayed turn
			case 'w':                     // shake
			case '~':                     // trill wavy line extension
			case 'c':                     // continued wavy line
			case 'M':                     // mordent
			case 'j':                     // slide (Schleifer)
			  // ornaments can be modified by accidentals:
			  //    s     = sharp
			  //    ss    = double sharp
			  //    f     = flat
			  //    ff    = double flat
			  //    h     = natural
			  //    u     = next accidental is under the ornament
			  // any combination of these characters following a
			  // ornament is considered one element.
			  //
			  count++;
			  index++;
			  while (input[index] == 's' || input[index] == 'f' ||
						input[index] == 'h' || input[index] == 'u') {
				  output += input[index++];
			  }
			  break;

			//////////////////////////////////////////////////////////////
			// The following chars are uniquely SINGLE letter items:    //
			//                                                          //
			//                                                          //
			case '-':                     // tie                        //
			case '(':                     // open  slur #1              //
			case ')':                     // close slur #1              //
			case '[':                     // open  slur #2              //
			case ']':                     // close slur #2              //
			case '{':                     // open  slur #3              //
			case '}':                     // close slur #3              //
			case 'z':                     // open  slur #4              //
			case 'x':                     // close slur #4              //
			case '*':                     // start written tuplet       //
			case '!':                     // end written tuplet         //
			case 'v':                     // up bow                     //
			case 'n':                     // down bow                   //
			case 'o':                     // harmonic                   //
			case 'O':                     // open string                //
			case 'Q':                     // thumb position             //
			case 'A':                     // accent (^)                 //
			case 'V':                     // accent (v)                 //
			case '>':                     // accent (>)                 //
			case '.':                     // staccatto                  //
			case '_':                     // tenuto                     //
			case '=':                     // detached tenuto            //
			case 'i':                     // spiccato                   //
			case '\'':                    // breath mark                //
			case 'F':                     // upright fermata            //
			case 'E':                     // inverted fermata           //
			case 'R':                     // rfz                        //
			case '^':                     // editorial accidental       //
			case '+':                     // cautionary accidental      //
				count++;                                                 //
				output += input[index++];                                //
				break;                                                   //
			//                                                          //
			//                                                          //
			//////////////////////////////////////////////////////////////
			case ' ':
				// ignore blank spaces and continue counting elements
				index++;
				break;
			default:
				cout << "Error: unknown additional notation: "
					  << input[index] << endl;
				return 0;
		}
		if (count != 0 || index >= 12) {
			finished = 1;
		}
	} // end of while (!finished) loop

	return count;
}