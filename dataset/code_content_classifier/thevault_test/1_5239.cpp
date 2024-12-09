bool ts::TablesLogger::isFiltered(const Section& sect, uint16_t cas)
{
    // By default, keep the section.
    bool status = true;

    // Call all section filters. Keep the section if all filters agree.
    // Make sure to call all filters, even after one returned false to collect additional PID's.
    for (auto it = _section_filters.begin(); it != _section_filters.end(); ++it) {
        PIDSet pids;
        if (!(*it)->filterSection(_duck, sect, cas, pids)) {
            status = false;
        }
        _demux.addPIDs(pids);
    }
    return status;
}