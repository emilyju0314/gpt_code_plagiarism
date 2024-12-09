void ts::TablesLogger::handleTable(SectionDemux&, const BinaryTable& table)
{
    // Give up if completed.
    if (completed()) {
        return;
    }

    assert(table.sectionCount() > 0);
    const PID pid = table.sourcePID();
    const uint16_t cas = _cas_mapper.casId(table.sourcePID());

    // Ignore table if not to be filtered. Keep the table if at least one section shall be kept.
    bool keep = false;
    for (size_t i = 0; !keep && i < table.sectionCount(); ++i) {
        keep = isFiltered(*table.sectionAt(i), cas);
    }
    if (!keep) {
        return;
    }

    // Ignore duplicate tables with a short section.
    if (_no_duplicate && table.isShortSection()) {
        if (_shortSections[pid].isNull() || *_shortSections[pid] != *table.sectionAt(0)) {
            // Not the same section, keep it for next time.
            _shortSections[pid] = new Section(*table.sectionAt(0), COPY);
        }
        else {
            // Same section as previously, ignore it.
            return;
        }
    }

    // Filtering done, now save data.
    if (_use_text) {
        preDisplay(table.getFirstTSPacketIndex(), table.getLastTSPacketIndex());
        if (_logger) {
            // Short log message
            logSection(*table.sectionAt(0));
        }
        else {
            // Full table formatting
            _display.displayTable(table, 0, _cas_mapper.casId(pid)) << std::endl;
        }
        postDisplay();
    }

    if (_use_xml) {
        // In case of rewrite for each table, create a new file.
        if (_rewrite_xml && !createXML(_xml_destination)) {
            return;
        }
        saveXML(table);
        if (_rewrite_xml) {
            closeXML();
        }
    }

    if (_use_binary) {
        // In case of rewrite for each table, create a new file.
        if (_rewrite_binary && !createBinaryFile(_bin_destination)) {
            return;
        }
        // Save each section in binary format
        for (size_t i = 0; i < table.sectionCount(); ++i) {
            saveBinarySection(*table.sectionAt(i));
        }
        if (_rewrite_binary) {
            _binfile.close();
        }
    }

    if (_use_udp) {
        sendUDP(table);
    }

    // Check max table count
    _table_count++;
    if (_max_tables > 0 && _table_count >= _max_tables) {
        _abort = true;
    }
}