static int rgbe_error(int rgbe_error_code, const char *msg) {
    switch (rgbe_error_code) {
        case rgbe_read_error:
            perror("RGBE read error");
            break;
        case rgbe_write_error:
            perror("RGBE write error");
            break;
        case rgbe_format_error:
            fprintf(stderr, "RGBE bad file format: %s\n", msg);
            break;
        default:
        case rgbe_memory_error:
            fprintf(stderr, "RGBE error: %s\n", msg);
    }
    return RGBE_RETURN_FAILURE;
}