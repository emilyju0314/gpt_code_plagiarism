HTp HumdrumFileBase::getTrackStart(int track) const {
	if ((track > 0) && (track < (int)m_trackstarts.size())) {
		return m_trackstarts[track];
	} else {
		return NULL;
	}
}