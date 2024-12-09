int load_leap_sec_data()
{
    char line[100];
    int ln = 0;
    while ((fgets(line, 99, ls_stream) != NULL) && (ln < MAX_NUM_LEAP_SEC)) {
        // 50083.0	1996 January 1 TAI-UTC = 30.0
        if (sscanf(line, "%ld %s %s %s",
                   &ls[ln].mjd, &ls[ln].yr, &ls[ln].month, &ls[ln].day) < 4) {
            printf ("Error reading dates in leap second file '%s', line %d\n",
                    leap_sec_file, ln + 1);
            return 0;
        }
        // skip to the '='
	int i;
        for (i = 0; i < strlen(line); i++) {
            if (line[i] == '=') {
                break;
            }
        }
        if (sscanf(&line[i+1], "%lf", &ls[ln].utc_offset) != 1) {
            printf (
              "Error reading utc_offset in leap second file '%s', line %d\n",
                    leap_sec_file, ln + 1);
            return 0;
        }
        ln++;
    }
    if (ln == MAX_NUM_LEAP_SEC) {
        printf ("May have exceeded the leap second file length limit\n");
        printf (" of %d lines.  Recompile 'astrtime.cc'n", MAX_NUM_LEAP_SEC);
    }
    num_leap_sec = ln;
    return ln;
}