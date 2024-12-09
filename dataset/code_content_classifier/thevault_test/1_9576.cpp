void MuseRecord::setNoteheadShape(HumNum duration) {
	HumNum  note8th(1,2);
	HumNum  note16th(1,4);
	HumNum  note32nd(1,8);
	HumNum  note64th(1,16);
	HumNum  note128th(1,32);
	HumNum  note256th(1,64);

	if (duration > 16) {                 // maxima
		setNoteheadMaxima();
	} else if (duration > 8) {           // long
		setNoteheadLong();
	} else if (duration > 4) {           // breve
		if (m_roundBreve) {
			setNoteheadBreveRound();
		} else {
			setNoteheadBreve();
		}
	} else if (duration > 2) {           // whole note
		setNoteheadWhole();
	} else if (duration > 1) {           // half note
		setNoteheadHalf();
	} else if (duration > note8th) {     // quarter note
		setNoteheadQuarter();
	} else if (duration > note16th) {    // eighth note
		setNotehead8th();
	} else if (duration > note32nd) {    // 16th note
		setNotehead16th();
	} else if (duration > note64th) {    // 32nd note
		setNotehead32nd();
	} else if (duration > note128th) {   // 64th note
		setNotehead64th();
	} else if (duration > note256th) {   // 128th note
		setNotehead128th();
	} else if (duration == note256th) {  // 256th note
		// not allowing tuplets on the 256th note level.
		setNotehead256th();
	} else {
		cerr << "Error in duration: " << duration << endl;
		return;
	}
}