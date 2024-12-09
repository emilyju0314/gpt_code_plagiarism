void HumTransposer::transpose(HumPitch &pitch, int transVal) {
	int ipitch = humHumPitchToIntegerPitch(pitch);
	ipitch += transVal;
	pitch = integerPitchToHumPitch(ipitch);
}