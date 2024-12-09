void ts::AbstractTablePlugin::reinsertTable(BinaryTable& table, bool is_target_table)
{
    // Make common modifications on target table.
    if (is_target_table) {
        tsp->verbose(u"%s version %d modified", {_table_name, table.version()});

        // The target table is found, no longer need to create a new one.
        _found_table = true;
        _pkt_insert = 0;

        // Modify the table version.
        if (_incr_version) {
            table.setVersion((table.version() + 1) & SVERSION_MASK);
        }
        else if (_set_version) {
            table.setVersion(_new_version);
        }
    }

    // Reinsert the table in the packetizer.
    if (table.isShortSection()) {
        _pzer.removeSections(table.tableId());
    }
    else {
        _pzer.removeSections(table.tableId(), table.tableIdExtension());
    }
    _pzer.addTable(table);
}