void qp_ctx::print_buffer(volatile void *buf,
                          int count) { // TODO: Move to utils.cc file
    int i = 0;
    int line_width = 16;
    int line_count = (count / sizeof(int)) / line_width;
    int line_seperator = 16;
    for (int line = 0; line < line_count; ++line) {
        // After every 'line_seperator' lines, print \n
        if ((line > 0) && (line >= line_seperator) &&
            (line % line_seperator == 0)) {
            fprintf(stderr, "\n");
        }
        fprintf(stderr, "#%02d: ", line);
        for (int column = 0; column < 16; ++column) {
            fprintf(stderr, "%08X  ",
                    ntohl(((int *)buf)[line * line_width + column]));
        }
        fprintf(stderr, "\n");
    }
    fprintf(stderr, "\n");
}