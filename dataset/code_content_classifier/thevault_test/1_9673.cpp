void GridSlice::addToken(const string& tok, int parti, int staffi, int voicei) {
	if ((parti < 0) || (parti >= (int)this->size())) {
		cerr << "Error: part index " << parti << " is out of range: size is ";
		cerr << this->size() << endl;
		return;
	}
	if (staffi < 0) {
		cerr << "Error: staff index " << staffi << " is out of range: size is ";
		cerr << this->at(parti)->size() << endl;
		return;
	}

	if (staffi >= (int)this->at(parti)->size()) {
		int ssize = (int)this->at(parti)->size();
		for (int i=ssize; i<=staffi; i++) {
			GridStaff* gs = new GridStaff;
			this->at(parti)->push_back(gs);
		}
	}

	if (voicei >= (int)this->at(parti)->at(staffi)->size()) {
		int oldsize = (int)this->at(parti)->at(staffi)->size();
		this->at(parti)->at(staffi)->resize(voicei+1);
		for (int j=oldsize; j<=voicei; j++) {
			this->at(parti)->at(staffi)->at(j) = new GridVoice;
		}
	}
	this->at(parti)->at(staffi)->at(voicei)->setToken(tok);
}