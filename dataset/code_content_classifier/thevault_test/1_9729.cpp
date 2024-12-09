Tool_semitones::Tool_semitones(void) {
	define("1|first=b", "mark only the first note of intervals");
	define("2|second=b", "mark only the second note of intervals");
	define("A|O|no-analysis|no-output=b", "do not print analysis spines");
	define("I|no-input=b", "do not print input data spines");
	define("M|no-mark|no-marks=b", "do not mark notes");
	define("R|no-rests=b", "ignore rests");
	define("T|no-ties=b", "do not mark ties");
	define("X|include|only=s", "include only **kern tokens with given pattern");
	define("color=s:red", "mark color");
	define("c|cdata=b", "store resulting data as **cdata (allowing display in VHV");
	define("d|down=b", "highlight notes that that have a negative semitone interval");
	define("j|jump=i:3", "starting interval defining leaps");
	define("l|leap=b", "highlight notes that have leap motion");
	define("mark=s:@", "mark character");
	define("m|midi=b", "show MIDI note number for pitches");
	define("n|count=b", "output count of intervals being marked");
	define("p|pc=b", "output pitch classes from C=0 instead of MIDI notes for -m option");
	define("r|same|repeat|repeated=b", "highlight notes that are repeated ");
	define("s|step=b", "highlight notes that have step-wise motion");
	define("u|up=b", "highlight notes that that have a positive semitone interval");
	define("x|exclude=s", "exclude **kern tokens with given pattern");
}