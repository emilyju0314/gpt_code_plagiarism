bool ts::DektecOutputPlugin::setPreloadFIFOSizeBasedOnDelay()
{
    if (_guts->preload_fifo_delay && _guts->cur_bitrate) {
        // calculate new preload FIFO size based on new bit rate
        // to calculate the size, in bytes, based on the bit rate and the requested delay, it is:
        // <bit rate (in bits/s)> / <8 bytes / bit> * <delay (in ms)> / <1000 ms / s>
        // converting to uint64_t because multiplying the current bit rate by the delay may exceed the max value for a uint32_t
        uint64_t prelimPreloadFifoSize = (uint64_t(_guts->cur_bitrate) * _guts->preload_fifo_delay) / 8000ULL;
        if (prelimPreloadFifoSize > uint64_t(_guts->fifo_size)) {
            _guts->preload_fifo_size = _guts->fifo_size;
            tsp->verbose(u"For --preload-fifo-delay, delay (%d ms) too large (%'d bytes), based on bit rate (%'d b/s) and FIFO size (%'d bytes). Using FIFO size for preload size instead.",
                {_guts->preload_fifo_delay, prelimPreloadFifoSize, _guts->cur_bitrate, _guts->fifo_size});
        }
        else {
            _guts->preload_fifo_size = int(prelimPreloadFifoSize);
        }

        return true;
    }

    return false;
}