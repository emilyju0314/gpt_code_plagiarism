void DGSCyberGlove::fillDataStructure(unsigned char *inBytes, DataGloveData *destStruct)
{
	// ---------- thumb
    destStruct->thumb[0]  = inBytes[1]; // rotation across palm
    destStruct->thumb[1]  = inBytes[2]; // inner phalanx
    destStruct->thumb[2]  = inBytes[3]; // outer phalanx
	// ---------- fingers (inner, middle outer phalanx for each finger)
	// index
	destStruct->index[0]  = inBytes[5];
	destStruct->index[1]  = inBytes[6];
	destStruct->index[2]  = inBytes[7];
	// middle
	destStruct->middle[0] = inBytes[8];
	destStruct->middle[1] = inBytes[9];
	destStruct->middle[2] = inBytes[10];
	// ring
	destStruct->ring[0]   = inBytes[12];
	destStruct->ring[1]   = inBytes[13];
	destStruct->ring[2]   = inBytes[14];
	// pinkie
	destStruct->pinkie[0] = inBytes[16];
	destStruct->pinkie[1] = inBytes[17];
	destStruct->pinkie[2] = inBytes[18];
	// ---------- finger-finger abductions
	destStruct->abduction[0] = inBytes[4];  // thumb-index relative abduction
	destStruct->abduction[1] = inBytes[11]; // index-middle relative abduction
	destStruct->abduction[2] = inBytes[15]; // middle-ring abduction
	destStruct->abduction[3] = inBytes[19]; // ring-pinkie abduction
	// ---------- palm arch
	destStruct->palmArch = inBytes[20];
	// ---------- wrist pitch
	destStruct->wristPitch = inBytes[21];
	// ---------- wrist yaw
	destStruct->wristYaw = inBytes[22];
}