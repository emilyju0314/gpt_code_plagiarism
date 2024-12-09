Tool_colortriads::Tool_colortriads(void) {
	define("A=b", "Do not color triads with diatonic A root");
	define("B=b", "Do not color triads with diatonic B root");
	define("C=b", "Do not color triads with diatonic C root");
	define("D=b", "Do not color triads with diatonic D root");
	define("E=b", "Do not color triads with diatonic E root");
	define("F=b", "Do not color triads with diatonic F root");
	define("G=b", "Do not color triads with diatonic G root");
	define("a=s:darkviolet",     "color for A triads");
	define("b=s:darkorange",     "color for B triads");
	define("c=s:limegreen",      "color for C triads");
	define("d=s:royalblue",      "color for D triads");
	define("e=s:crimson",        "color for E triads");
	define("f=s:gold",           "color for F triads");
	define("g=s:skyblue",        "color for G triads");
	define("r|relative=b",       "functional coloring (green = key tonic)");
	define("k|key=s",            "key to transpose coloring to");
	define("commands=b",         "print msearch commands only");
	define("filters=b",          "print filter commands only");
}