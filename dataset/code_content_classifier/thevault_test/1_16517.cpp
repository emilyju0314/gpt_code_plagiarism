static void appendClassName(StringBuilder& builder, const char* className)
{
#if USE(JSC)
    ASSERT(JSLock::lockCount() > 0);
#endif

    char* c = fastStrDup(className);

    char* result = c;
    while (*c) {
        if (*c == '.')
            *c = '/';
        c++;
    }

    builder.append(result);

    fastFree(result);
}