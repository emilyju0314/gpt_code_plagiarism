static char *addenv(struct cgi_env_block *block, const char *fmt, ...) {
    int n, space;
    char *added = block->buf + block->len;
    va_list ap;

    /* Calculate how much space is left in the buffer */
    space = sizeof(block->buf) - (block->len + 2);
    if (space > 0) {
        /* Copy VARIABLE=VALUE\0 string into the free space */
        va_start(ap, fmt);
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wformat-nonliteral"
        n = vsnprintf(added, (size_t) space, fmt, ap);
#pragma GCC diagnostic pop
        va_end(ap);

        /* Make sure we do not overflow buffer and the envp array */
        if (n > 0 && n + 1 < space &&
                block->nvars < (int) ARRAY_SIZE(block->vars) - 2) {
            /* Append a pointer to the added string into the envp array */
            block->vars[block->nvars++] = added;
            /* Bump up used length counter. Include \0 terminator */
            block->len += n + 1;
        }
    }

    return added;
}