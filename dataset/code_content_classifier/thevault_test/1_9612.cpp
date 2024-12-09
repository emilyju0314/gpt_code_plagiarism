Tool_autoaccid::Tool_autoaccid(void) {
	define("x|visual=b", "mark visual accidentals only");
	define("y|suppressed=b", "mark hidden accidentals only");
	define("r|remove=b", "remove accidental qualifications");
	define("c|keep-cautionary|keep-courtesy|cautionary|caution|courtesy=b", "keep cautionary accidentals when removing markers");
}