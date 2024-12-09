void Tool_autostem::removeStem2(HumdrumFile& infile, int row, int col) {
	HumRegex hre;
	hre.replaceDestructive(infile.token(row, col), "", "[\\\\/]x(?!x)", "g");
	hre.replaceDestructive(infile.token(row, col), "", "[\\\\/](?!x)", "g");
}