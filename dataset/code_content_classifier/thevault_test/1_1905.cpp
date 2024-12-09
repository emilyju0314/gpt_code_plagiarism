void panic(const char *fmt, ...)
{
    static char message[131072];
    va_list ap;

    va_start(ap, fmt);
    vsnprintf(message, sizeof message, fmt, ap);
    printf(message); fflush(stdout);
    va_end(ap);

    exit(1);
}