int Address::str2addr(char *str)
{
	if (levels_ == 0) 
		return atoi(str);
	char *delim = ".";
	char *tok;
	int addr;
	for (int i = 1; i <= levels_; i++) {
		if (i == 1) {
			tok = strtok(str, delim);
			addr = atoi(tok);
		} else {
			tok = strtok(NULL, delim);
			addr = set_word_field(addr, atoi(tok), 
					      NodeShift_[i], NodeMask_[i]);
		}
	}
	return addr;
}