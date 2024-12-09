void ts::TablesLogger::handleSection(SectionDemux& demux, const Section& sect)
{
    const PID pid = sect.sourcePID();
    const uint16_t cas = _cas_mapper.casId(sect.sourcePID());

    // With option --all-once, track duplicate PID/TID/TDIext/secnum/version.
    if (_all_once) {
        // Pack PID/TID/TDIext/secnum/version into one single 64-bit integer.
        const uint64_t id =
            (uint64_t(pid) << 40) |
            (uint64_t(sect.tableId()) << 32) |
            (uint64_t(sect.tableIdExtension()) << 16) |
            (uint64_t(sect.sectionNumber()) << 8) |
            uint64_t(sect.version());
        if (_sectionsOnce.count(id) != 0) {
            // Already found this one, give up.
            return;
        }
        else {
            // Remember this combination.
            _sectionsOnce.insert(id);
        }
    }

    // With option --pack-all-sections, force the processing of a complete table.
    if (_pack_all_sections) {
        BinaryTable table;
        table.addSection(new Section(sect, SHARE));
        table.packSections();
        if (table.isValid()) {
            handleTable(demux, table);
        }
        return;
    }

    // Give up if completed.
    if (completed()) {
        return;
    }

    // Ignore section if not to be filtered
    if (!isFiltered(sect, cas)) {
        return;
    }

    // Ignore duplicate sections.
    if (_no_duplicate) {
        if (_allSections[pid].isNull() || *_allSections[pid] != sect) {
            // Not the same section, keep it for next time.
            _allSections[pid] = new Section(sect, COPY);
        }
        else {
            // Same section as previously, ignore it.
            return;
        }
    }

    // Filtering done, now save data.
    // Note that no XML can be produced since valid XML structures contain complete tables only.

    if (_use_text) {
        preDisplay(sect.getFirstTSPacketIndex(), sect.getLastTSPacketIndex());
        if (_logger) {
            // Short log message
            logSection(sect);
        }
        else {
            // Full section formatting.
            _display.displaySection(sect, 0, _cas_mapper.casId(pid)) << std::endl;
        }
        postDisplay();
    }

    if (_use_binary) {
        // In case of rewrite for each section, create a new file.
        if (_rewrite_binary && !createBinaryFile(_bin_destination)) {
            return;
        }
        saveBinarySection(sect);
        if (_rewrite_binary) {
            _binfile.close();
        }
    }

    if (_use_udp) {
        sendUDP(sect);
    }

    // Check max table count (actually count sections with --all-sections)
    _table_count++;
    if (_max_tables > 0 && _table_count >= _max_tables) {
        _abort = true;
    }
}