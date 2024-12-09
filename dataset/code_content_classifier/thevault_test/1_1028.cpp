void soundDevice::setOrientation(float atx, float aty, float atz,
	float upx, float upy, float upz) {
	
	std::vector<float> orientation;

	//add info to the orientation vector
	orientation.push_back(atx);
	orientation.push_back(aty);
	orientation.push_back(atz);
	orientation.push_back(upx);
	orientation.push_back(upy);
	orientation.push_back(upz);

	alListenerfv(AL_ORIENTATION, orientation.data());
}