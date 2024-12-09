int load_iers_data()
{
    char line[100];
    int ln = 0;
    while ((fgets(line, 99, iers_stream) != NULL) &&
                                          (ln < MAX_NUM_IERS_OFFSETS)) {
        //  MJD      x       y     UT1 - UTC
        // 50060  -.12288  .12426  -.389102
        if (sscanf(line,"%ld %lf %lf %lf",
                   &iers[ln].mjd, &iers[ln].x, &iers[ln].y,
                   &iers[ln].ut1_offset) < 4) {
            printf ("Error reading dates in IERS file '%s', line %d\n",
                    iers_file, ln + 1);
            return 0;
        }
        ln++;
    }
    if (ln == MAX_NUM_IERS_OFFSETS) {
        printf ("May have exceeded the IERS file length limit\n");
        printf (" of %d lines.  Recompile 'astrtime.cc'n",
                MAX_NUM_IERS_OFFSETS);
    }
    num_iers_offsets = ln;
    return ln;
}