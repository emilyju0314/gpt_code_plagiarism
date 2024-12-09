void ts::TablesLogger::close()
{
    if (!_exit) {

        // Pack sections in incomplete tables if required.
        if (_pack_and_flush) {
            _demux.packAndFlushSections();
        }
        if (_fill_eit) {
            _demux.fillAndFlushEITs();
        }

        // Close files and documents.
        closeXML();
        if (_binfile.is_open()) {
            _binfile.close();
        }
        if (_sock.isOpen()) {
            _sock.close(_report);
        }

        // Now completed.
        _exit = true;
    }
}