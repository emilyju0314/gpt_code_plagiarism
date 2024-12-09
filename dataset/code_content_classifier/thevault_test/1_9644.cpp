void HumTransposer::transpose(HumPitch &pitch) {
	int ipitch = humHumPitchToIntegerPitch(pitch);
	ipitch += m_transpose;
	pitch = integerPitchToHumPitch(ipitch);
}