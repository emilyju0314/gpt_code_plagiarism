void numword::appendspace() {
    if (_buflen) {
        appendbuf( hyphen_flag ? _hyphen : _space);
        hyphen_flag = false;
    }
}