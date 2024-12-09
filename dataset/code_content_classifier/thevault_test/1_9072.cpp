string LogLine::formatedString(bool includeDate) const {
	// Convert date to string with format "HH:MM::SS.mmm"
	char time[13];
	int ms = duration_cast<milliseconds>(date.time_since_epoch()).count() % 1000;
	time_t rawtime = system_clock::to_time_t(date);
	size_t len = strftime(time, 9, "%T", localtime(&rawtime));
	sprintf(time+len, ".%03d", ms);

	// Insert date between the tag and the content
	string res;
	int offset = 2;
	if(str.find(headerError) == 0)
		res += headerError;
	else if(str.find(headerWarning) == 0)
		res += headerWarning;
	else if(str.find(headerDebug) == 0)
		res += headerDebug;
	else if(str.find(headerInfo) == 0)
		res += headerInfo;
	else {
		offset = 0;
		res += headerDefault;
	}

	if(includeDate) {
		res += time;
		res += '/';
	}
	res += str.substr(offset);

	return res;
}