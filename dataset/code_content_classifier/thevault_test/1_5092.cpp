void ts::AbstractTablePlugin::forceTableUpdate(BinaryTable& table)
{
    // Common processing of target table.
    reinsertTable(table, true);

    // Insert first packet as soon as possible when the target PID is not present.
    _pkt_insert = tsp->pluginPackets();
}