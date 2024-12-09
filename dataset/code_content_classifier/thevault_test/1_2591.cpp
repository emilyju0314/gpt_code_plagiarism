static void adjust_itable(iline *table, int n, unsigned int max_avail) {
    // Adjust the end first
    while (n && table[--n].line > max_avail) {
        table[n].line = max_avail;
        table[n].w = 255; // Mostly the last available line
    }
    for (int i = 0; i < n && table[i].line <= 0; i++) {
        table[i].line = 1;
        table[i].w = 0; // Use line zero value
    }
}