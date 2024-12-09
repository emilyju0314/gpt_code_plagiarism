void MuseRecord::setNoteheadShapeMensural(HumNum duration) {
	HumNum note8th(1, 2);
	HumNum note16th(1, 4);
	HumNum note32th(1, 8);
	HumNum note64th(1, 16);
	HumNum note128th(1, 32);
	HumNum note256th(1, 64);

	if (duration > 16) {                 // maxima
		setNoteheadMaxima();
	} else if (duration > 8) {           // long
		setNoteheadLong();
	} else if (duration > 4) {           // breve
		setNoteheadBreve();
	} else if (duration > 2) {           // whole note
		setNoteheadWholeMensural();
	} else if (duration > 1) {           // half note
		setNoteheadHalfMensural();
	} else if (duration > note8th) {     // quarter note
		setNoteheadQuarterMensural();
	} else if (duration > note16th) {    // eighth note
		setNotehead8thMensural();
	} else if (duration > note32th) {    // 16th note
		setNotehead16thMensural();
	} else if (duration > note64th) {    // 32nd note
		setNotehead32ndMensural();
	} else if (duration > note128th) {   // 64th note
		setNotehead64thMensural();
	} else if (duration > note256th) {   // 128th note
		setNotehead128thMensural();
	} else if (duration >= note256th) {  // 256th note
		// don't allow tuplets on 256th note level.
		setNotehead256thMensural();
	} else {
		cerr << "Error in duration: " << duration << endl;
		return;
	}
}