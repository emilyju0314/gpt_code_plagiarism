void clawAction(bool action){
	float grabMin = 70.0;
	float grabMax = 130.0;
	if (action){
		posGrab = grabMin;
	}else {
		posGrab = grabMax;
	}
}