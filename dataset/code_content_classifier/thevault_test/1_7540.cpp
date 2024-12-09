static void _ghost_dprf(const char *format, ...)
{
    va_list argp;
    va_start(argp, format);

#ifndef DEBUG_DIAGNOSTICS
    const bool wiz_cmd = (crawl_state.prev_cmd == CMD_WIZARD);
    if (wiz_cmd)
#endif
        do_message_print(MSGCH_DIAGNOSTICS, 0, false, false, format, argp);

    va_end(argp);
}