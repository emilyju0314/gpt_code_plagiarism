bool GCToOSInterface::ParseGCHeapAffinitizeRangesEntry(const char** config_string, size_t* start_index, size_t* end_index)
{
    assert(g_fEnableGCCPUGroups);

    char* number_end;
    size_t group_number = strtoul(*config_string, &number_end, 10);

    if ((number_end == *config_string) || (*number_end != ':'))
    {
        // No number or no colon after the number found, invalid format
        return false;
    }

    if (group_number >= g_nGroups)
    {
        // Group number out of range
        return false;
    }

    *config_string = number_end + 1;

    size_t start, end;
    if (!ParseIndexOrRange(config_string, &start, &end))
    {
        return false;
    }

    uint16_t group_processor_count = g_CPUGroupInfoArray[group_number].nr_active;
    if ((start >= group_processor_count) || (end >= group_processor_count))
    {
        // Invalid CPU index values or range
        return false;
    }

    uint16_t group_begin = g_CPUGroupInfoArray[group_number].begin;

    *start_index = group_begin + start;
    *end_index = group_begin + end;

    return true;
}