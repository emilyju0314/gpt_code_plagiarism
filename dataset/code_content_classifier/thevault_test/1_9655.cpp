int Tool_autostem::getBeamDirection(vector<Coord>& coords,
		vector<vector<int> >& voice, vector<vector<vector<int> > >& notepos) {

	// voice values are presumed to be 0 at the moment.

	int minn = 1000;
	int maxx = -1000;

	int x;
	int i, j, k;
	for (x=0; x<(int)coords.size(); x++) {
		i = coords[x].i;
		j = coords[x].j;
		if (voice[i][j] == 1) {
			return +1;
		}
		if (voice[i][j] == 2) {
			return -1;
		}
		for (k=0; k<(int)notepos[i][j].size(); k++) {
			if (minn > notepos[i][j][k]) {
				minn = notepos[i][j][k];
			}
			if (maxx < notepos[i][j][k]) {
				maxx = notepos[i][j][k];
			}
		}
	}

	if (maxx < 0 + Borderline) {
		// both minn and maxx are less than zero, so place stems up
		return +1;
	}
	if (minn > 0) {
		// both minn and maxx are greater than zero, so place stems down
		return -1;
	}

	if (abs(maxx) > abs(minn)) {
		// highest note is higher than lower note is lower, so place
		// stems down
		return -1;
	}
	if (abs(maxx) > abs(minn)) {
		// highest note is lower than lower note is lower, so place
		// stems up
		return +1;
	}

	// its a draw, so place stem up.
	return +1;
}