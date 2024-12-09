void numword::appendbuf(const char * s) {
    if(!s) return;
    size_t slen = strnlen(s, _maxstr);
    if (slen < 1) {
        return;
    }
    if ((slen + _buflen + 1) >= _maxstr) {
        return;
    }
    memcpy(_buf + _buflen, s, slen);
    _buflen += slen;
    _buf[_buflen] = 0;
}