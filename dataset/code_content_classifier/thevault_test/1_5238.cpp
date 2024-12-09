void ts::TablesLogger::saveBinarySection(const Section& sect)
{
    // Create individual file for this section if required.
    if (_multi_files) {
        // Build a unique file name for this section
        UString outname(PathPrefix(_bin_destination));
        outname += UString::Format(u"_p%04X_t%02X", {sect.sourcePID(), sect.tableId()});
        if (sect.isLongSection()) {
            outname += UString::Format(u"_e%04X_v%02X_s%02X", {sect.tableIdExtension(), sect.version(), sect.sectionNumber()});
        }
        outname += PathSuffix(_bin_destination);
        // Create the output file
        if (!createBinaryFile(outname)) {
            return;
        }
    }

    // Write the section to the file
    if (!sect.write(_binfile, _report)) {
        _abort = true;
    }

    // Close individual files
    if (_multi_files) {
        _binfile.close();
    }
}