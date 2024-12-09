Tool_homorhythm2::Tool_homorhythm2(void) {
	define("t|threshold=d:1.6", "Threshold score sum required for homorhythm texture detection");
	define("u|threshold2=d:1.3", "Threshold score sum required for semi-homorhythm texture detection");
	define("s|score=b", "Show numeric scores");
	define("n|length=i:4", "Sonority length to calculate");
	define("f|fraction=b", "Report fraction of music that is homorhythm");
}