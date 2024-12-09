ts::UString ts::CellListDescriptor::ToDegrees(int32_t value, bool is_latitude)
{
    // Convert value as a positive value, in 2^15 degrees. 
    UChar orientation = CHAR_NULL;
    if (is_latitude) {
        if (value >= 0) {
            orientation = 'N';
            value = value * 90;
        }
        else {
            orientation = 'S';
            value = -value * 90;
        }
    }
    else {
        if (value >= 0) {
            orientation = 'E';
            value = value * 180;
        }
        else {
            orientation = 'W';
            value = -value * 180;
        }
    }

    // Compute degrees, minutes, seconds.
    int32_t deg = value / 0x8000;
    int32_t sec = ((value % 0x8000) * 3600) / 0x8000;
    return UString::Format(u"%d%c %d' %d\" %c", {deg, MASCULINE_ORDINAL_INDICATOR, sec / 60, sec % 60, orientation});
}