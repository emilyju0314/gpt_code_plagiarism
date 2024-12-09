void ts::BitrateMonitorPlugin::checkTime()
{
    const time_t now = ::time(nullptr);

    // NOTE : the computation method used here is meaningful only if at least
    // one packet is received per second (whatever its PID).

    // New second : compute the bitrate for the last time window
    if (now > _last_second) {

        // Bitrate computation is done only when the packet counter
        // array if fully filled (to avoid bad values at startup).
        if (!_startup) {
            computeBitrate();
        }

        // update index, and reset packet count.
        _pkt_count_index = (_pkt_count_index + 1) % _pkt_count.size();
        _pkt_count[_pkt_count_index] = 0;

        // We are no more at startup if the index cycles.
        if (_startup) {
            _startup = _pkt_count_index != 0;
        }

        _last_second = now;
    }
}