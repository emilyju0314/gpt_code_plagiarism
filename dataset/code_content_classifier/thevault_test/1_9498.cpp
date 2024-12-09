Tool_imitation::Tool_imitation(void) {
	define("debug=b",             "print grid cell information");
	define("e|exinterp=s:**vvdata","specify exinterp for **vvdata spine");

	define("n|t|threshold=i:7",   "minimum number of notes to match");
	define("f|first=b",           "only give info for first sequence of matched pair");

	define("q|quiet|no-info=b",   "do not add spines giving information about matches");

	define("N|no-enumeration=b",  "do not display enumeration number");
	define("C|no-count=b",        "do not display note-count number");
	define("D|no-distance=b",     "do not display distance between first notes of sequences");
	define("I|no-interval=b",     "do not display interval transposite between sequences");

	define("NN|no-enumeration2=b", "do not display enumeration number on second sequence");
	define("CC|no-count2=b",       "do not display note-count number on second sequence");
	define("DD|no-distance2=b",    "do not display distance between first notes of sequences on second sequence");
	define("II|no-interval2=b",    "do not display interval transposition between sequences on second sequence");
	define("2|enumerate-second-only=b", "Display enumeration number on second sequence only (no count, distance, or interval");

	define("p|no-duration=b",     "pitch only when matching: do not consider duration");
	define("d|max-distance=d",    "maximum distance in quarter notes between imitations");
	define("s|single-mark=b",     "place a single mark on matched notes (not one for each match pair");
	define("r|rest=b",            "require match trigger to follow a rest");
	define("R|rest2=b",           "require match target to also follow a rest");
	define("i|intervals=s",       "require given interval sequence in imitation");
	define("M|no-mark=b",         "do not mark matched sequences");
	define("Z|no-zero=b",         "do not mark imitation starting at the same time");
	define("z|only-zero=b",       "Mark only imitation starting at the same time (parallel motion)");
	define("m|measure=b",         "Include measure number in imitation information");
	define("b|beat=b",            "Include beat number (really quarter-note number) in imitation information");
	define("l|length=b",          "Include length of imitation (in quarter-note units)");

	define("a|add=b",             "add inversions, retrograde, etc. if specified to normal search");
	define("v|inversion=b",       "match inversions");
	define("g|retrograde=b",      "match retrograde");
}