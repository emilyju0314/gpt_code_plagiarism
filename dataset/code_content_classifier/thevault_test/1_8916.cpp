void usage()
{
    printf("Usage: validate_tld [-<opts>] <uri> | <email>\n");
    printf("Where <uri> or <email> are URIs starting with a valid scheme.\n");
    printf("The <email> scheme is mailto:.\n");
    printf("Where -<opts> are:\n");
    printf("  -h | --help               print out this help screen\n");
    printf("  -l | --list               print the default list of schemes\n");
    printf("  -s | --schemes <list>     set the list of schemes with user's defined schemes\n");
    printf("                            the list is a comma separate set of scheme names\n");
    printf("  -v | --verbose            request some verbosity of the tool's work\n");
    exit(1);
}