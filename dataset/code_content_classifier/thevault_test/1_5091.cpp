void ts::AbstractTablePlugin::handleTable(SectionDemux& demux, const BinaryTable& intable)
{
    // Filter out call for some other demux (maybe from a suclass).
    if (&demux != &_demux) {
        return;
    }

    // Build a modifiable version of the table.
    BinaryTable table(intable, SHARE);

    // Call subclass to process the table.
    bool is_target = true;
    bool reinsert = true;
    modifyTable(table, is_target, reinsert);

    // Place modified table in the packetizer.
    if (reinsert) {
        reinsertTable(table, is_target);
    }
}