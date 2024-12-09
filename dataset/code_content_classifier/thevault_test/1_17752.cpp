static int RGBE_WriteBytes_RLE(FILE *fp, unsigned char *data, int numbytes) {
#define MINRUNLENGTH 4
    int cur, beg_run, run_count, old_run_count, nonrun_count;
    unsigned char buf[2];

    cur = 0;
    while (cur < numbytes) {
        beg_run = cur;
        /* find next run of length at least 4 if one exists */
        run_count = old_run_count = 0;
        while ((run_count < MINRUNLENGTH) && (beg_run < numbytes)) {
            beg_run += run_count;
            old_run_count = run_count;
            run_count = 1;
            while ((data[beg_run] == data[beg_run + run_count])
                   && (beg_run + run_count < numbytes) && (run_count < 127))
                run_count++;
        }
        /* if data before next big run is a short run then write it as such */
        if ((old_run_count > 1) && (old_run_count == beg_run - cur)) {
            buf[0] = 128 + old_run_count;   /*write short run*/
            buf[1] = data[cur];
            if (fwrite(buf, sizeof(buf[0]) * 2, 1, fp) < 1)
                return rgbe_error(rgbe_write_error, NULL);
            cur = beg_run;
        }
        /* write out bytes until we reach the start of the next run */
        while (cur < beg_run) {
            nonrun_count = beg_run - cur;
            if (nonrun_count > 128)
                nonrun_count = 128;
            buf[0] = nonrun_count;
            if (fwrite(buf, sizeof(buf[0]), 1, fp) < 1)
                return rgbe_error(rgbe_write_error, NULL);
            if (fwrite(&data[cur], sizeof(data[0]) * nonrun_count, 1, fp) < 1)
                return rgbe_error(rgbe_write_error, NULL);
            cur += nonrun_count;
        }
        /* write out next run if one was found */
        if (run_count >= MINRUNLENGTH) {
            buf[0] = 128 + run_count;
            buf[1] = data[beg_run];
            if (fwrite(buf, sizeof(buf[0]) * 2, 1, fp) < 1)
                return rgbe_error(rgbe_write_error, NULL);
            cur += run_count;
        }
    }
    return RGBE_RETURN_SUCCESS;
#undef MINRUNLENGTH
}