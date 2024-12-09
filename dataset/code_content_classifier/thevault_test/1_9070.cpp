int LogLine::getColor() const {
	if(str.find(headerError) == 0)
		return 0xff0000ff;
	else if(str.find(headerWarning) == 0)
		return 0xeeaa00ff;
	else if(str.find(headerDebug) == 0)
		return 0xdd00ddff;
	else if(str.find(headerInfo) == 0)
		return 0x0000ddff;
	else
		return 0xddddddff;

}