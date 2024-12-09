void Tool_satb2gs::getTrackInfo(vector<vector<int>>& tracks, HumdrumFile& infile) {
	tracks.resize(5);
	for (int i=0; i<(int)tracks.size(); i++) {
		tracks[i].clear();
	}
	vector<HTp> sstarts;
	infile.getSpineStartList(sstarts);
	int track;

	// fill in tracks[0]: spines before first **kern spine
	for (int i=0; i<(int)sstarts.size(); i++) {
		if (sstarts[i]->isKern()) {
			break;
		}
		track = sstarts[i]->getTrack();
		tracks[0].push_back(track);
	}

	int kcount = 0;

	kcount = 0;
	// Store tracks related to the tenor part:
	for (int i=0; i<(int)sstarts.size(); i++) {
		if (sstarts[i]->isKern()) {
			kcount++;
		}
		if (kcount > 2) {
			break;
		}
		if (kcount < 2) {
			continue;
		}
		track = sstarts[i]->getTrack();
		if (sstarts[i]->isKern()) {
			tracks[1].push_back(track);
		} else {
			tracks[2].push_back(track);
		}
	}

	kcount = 0;
	// Store tracks related to the bass part:
	for (int i=0; i<(int)sstarts.size(); i++) {
		if (sstarts[i]->isKern()) {
			kcount++;
		}
		if (kcount > 1) {
			break;
		}
		if (kcount < 1) {
			continue;
		}
		track = sstarts[i]->getTrack();
		if (sstarts[i]->isKern()) {
			tracks[1].push_back(track);
		} else {
			tracks[2].push_back(track);
		}
	}

	kcount = 0;
	// Store tracks related to the soprano part:
	for (int i=0; i<(int)sstarts.size(); i++) {
		if (sstarts[i]->isKern()) {
			kcount++;
		}
		if (kcount > 4) {
			break;
		}
		if (kcount < 4) {
			continue;
		}
		track = sstarts[i]->getTrack();
		if (sstarts[i]->isKern()) {
			tracks[3].push_back(track);
		} else {
			tracks[4].push_back(track);
		}
	}

	kcount = 0;
	// Store tracks related to the alto part:
	for (int i=0; i<(int)sstarts.size(); i++) {
		if (sstarts[i]->isKern()) {
			kcount++;
		}
		if (kcount > 3) {
			break;
		}
		if (kcount < 3) {
			continue;
		}
		track = sstarts[i]->getTrack();
		if (sstarts[i]->isKern()) {
			tracks[3].push_back(track);
		} else {
			tracks[4].push_back(track);
		}
	}
}