static void segvh(int sig)
{
    std::cerr << "SIGSEGV detected" << std::endl;

    void *trace[16];
    char **messages = static_cast< char **> ( NULL );
    int i, trace_size = 0;

    trace_size = backtrace(trace, 16);
    messages = backtrace_symbols(trace, trace_size);

    for ( i=0; i< trace_size; ++i )
    {
        std::cerr << i << ": " << messages[i] << std::endl;
    }

    free( messages );

    // terminate
    abort();
}