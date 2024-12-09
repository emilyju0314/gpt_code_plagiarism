void MuseRecord::addMeasureFlag(const string& strang) {
	string flags = getColumns(17, 80);
	string flag = strang;

	HumRegex hre;
	hre.replaceDestructive(flag, "\\*", "\\*", "g");
	hre.replaceDestructive(flag, "\\|", "\\|", "g");
	if (hre.search(flags, flag)) {
		// flag was already found in flags, so don't do anything
		return;
	}
	hre.replaceDestructive(flags, "", "\\s+$");
	flags += " ";
	flags += strang;
	setColumns(flags, 17, 80);
}