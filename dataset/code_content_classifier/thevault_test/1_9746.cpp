void Tool_extract::removeDollarsFromString(string& buffer, int maxtrack) {
	HumRegex hre;
	char buf2[128] = {0};
	int value2;

	if (hre.search(buffer, "\\$$")) {
		sprintf(buf2, "%d", maxtrack);
		hre.replaceDestructive(buffer, buf2, "\\$$");
	}

	if (hre.search(buffer, "\\$(?![\\d-])")) {
		// don't know how this case could happen, however...
		sprintf(buf2, "%d", maxtrack);
		hre.replaceDestructive(buffer, buf2, "\\$(?![\\d-])", "g");
	}

	if (hre.search(buffer, "\\$0")) {
		// replace $0 with maxtrack (used for reverse orderings)
		sprintf(buf2, "%d", maxtrack);
		hre.replaceDestructive(buffer, buf2, "\\$0", "g");
	}

	while (hre.search(buffer, "\\$(-?\\d+)")) {
		value2 = maxtrack - abs(hre.getMatchInt(1));
		sprintf(buf2, "%d", value2);
		hre.replaceDestructive(buffer, buf2, "\\$-?\\d+");
	}
}