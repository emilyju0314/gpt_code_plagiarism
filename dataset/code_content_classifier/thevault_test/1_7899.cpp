void processMouseLeave(int state)
{
	if( state == GLUT_LEFT ) {
		InitKeyFlags();

		// Kent Dolan feature request, don't stop sim when
		// leaving window.
		//
		// pause_sim = true;


		MakeCells(universe, true);

	} else if( state == GLUT_ENTERED ) {
		// do nothing
	}
}