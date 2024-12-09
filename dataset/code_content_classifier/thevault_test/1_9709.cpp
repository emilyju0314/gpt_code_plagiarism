void MuseRecordBasic::setLayer(int layer) {
	if (layer < 0) {
		m_layer = 0;
	} else {
		m_layer = layer;
	}
}