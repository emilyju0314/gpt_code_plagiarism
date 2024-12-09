in_addr_t* SNMP::getAgentAddr()
{
#if HAVE_GETHOSTBYNAME_R == 1
    struct hostent he, *phe = NULL;
    BinaryData buff(2048);
    int fnord = 0;
    if (gethostbyname_r("localhost", &he,
                        static_cast<char*>(buff.toVoid()),
                        buff.size(), &phe, &fnord))
    {
        throw Exception(__FILE__, __LINE__,
                        "Error %d in gethostbyname_r(): %s",
                        fnord, strerror(fnord));
    }
#elif HAVE_GETHOSTBYNAME_R == 0
    struct hostent *phe = ::gethostbyname("localhost");
#else
#error "No have gethostbyname_r check"
#endif
    if (phe == NULL)
    {
        assert(0);
        return NULL;
    }

    struct sockaddr_in saddr;
    memcpy(&saddr.sin_addr, phe->h_addr, phe->h_length);
    in_addr_t* result = static_cast<in_addr_t*>(calloc(sizeof(in_addr_t), 1));
    if (result == NULL)
    {
        klk_log(KLKLOG_ERROR, "Memory allocation error");
        return NULL;
    }
    memcpy(result, &saddr.sin_addr.s_addr, sizeof(in_addr_t));
    return result;
}