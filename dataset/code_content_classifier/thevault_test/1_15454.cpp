static void Help(char* progname)
{
	PRN("");
	PRN("Usage: %s [-d] [-no_rm_bup] SOURCE DEST", progname ? programname(progname) : "program");
	PRN("");
	PRN("K2HASH REPLACE TOOL: Replace k2hash file from SOURCE to DEST.");
	PRN("");
	PRN("The source file is moved destination file path, and destination");
	PRN("file is moved with suffix.");
	PRN("");
	PRN("SOURCE               source file path.");
	PRN("DEST                 destination k2hash file path.");
	PRN("-no_rm_bup           not remove backup files before working.");
	PRN("-d                   debug option.");
	PRN("");
}