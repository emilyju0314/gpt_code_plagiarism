void Tool_esac2hum::chopExtraInfo(char* holdbuffer) {
	int length = (int)strlen(holdbuffer);
	int i;
	int spacecount = 0;
	for (i=length-2; i>=0; i--) {
		if (holdbuffer[i] == ' ') {
			spacecount++;
			if (spacecount > 10) {
				holdbuffer[i] = '\0';
				break;
			}
		} else {
			spacecount = 0;
		}
	}
}