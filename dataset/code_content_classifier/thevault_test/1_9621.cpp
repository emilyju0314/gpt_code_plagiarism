Tool_gasparize::Tool_gasparize(void) {
	define("R|no-reference-records=b", "Do not add reference records");
	define("r|only-add-reference-records=b", "Only add reference records");

	define("B|do-not-delete-breaks=b", "Do not delete system/page break markers");
	define("b|only-delete-breaks=b", "only delete breaks");

	define("A|do-not-fix-instrument-abbreviations=b", "Do not fix instrument abbreviations");
	define("a|only-fix-instrument-abbreviations=b", "Only fix instrument abbreviations");

	define("E|do-not-fix-editorial-accidentals=b", "Do not fix instrument abbreviations");
	define("e|only-fix-editorial-accidentals=b", "Only fix editorial accidentals");

	define("T|do-not-add-terminal-longs=b", "Do not add terminal long markers");
	define("t|only-add-terminal-longs=b", "Only add terminal longs");

	define("no-ties=b", "Do not fix tied notes");

	define("N|do-not-remove-empty-transpositions=b", "Do not remove empty transposition instructions");
	define ("n|only-remove-empty-transpositions=b", "Only remove empty transpositions");
}