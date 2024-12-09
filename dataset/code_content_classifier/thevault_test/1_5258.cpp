bool ts::SRTSocket::receive(void* data, size_t max_size, size_t& ret_size, ts::Report& report)
{
    const int ret = srt_recv(_guts->sock, reinterpret_cast<char*>(data), int(max_size));
    if (ret < 0) {
        report.error(u"error during srt_recv(), msg: %s", { srt_getlasterror_str() });
        return false;
    }
    ret_size = size_t(ret);
    return true;
}