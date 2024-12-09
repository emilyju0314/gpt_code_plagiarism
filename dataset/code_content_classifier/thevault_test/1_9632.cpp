Tool_homorhythm::Tool_homorhythm(void) {
	define("a|append=b", "Append analysis to end of input data");
	define("attacks=b", "Append attack counts for each sonority");
	define("p|prepend=b", "Prepend analysis to end of input data");
	define("r|raw-sonority=b", "Display individual sonority scores only");
	define("raw-score=b", "Display accumulated scores");
	define("M|no-marks=b", "Do not mark homorhythm section notes");
	define("f|fraction=b", "calculate fraction of music that is homorhythm");
	define("v|voice=b", "display voice information or fraction results");
	define("F|filename=b", "show filename for f option");
	define("n|t|threshold=d:4.0", "Threshold score sum required for homorhythm texture detection");
	define("s|score=d:1.0", "Score assigned to a sonority with three or more attacks");
	define("m|intermediate-score=d:0.5", "Score to give sonority between two adjacent attack sonoroties");
	define("l|letter=b", "Display letter scoress before calculations");
}