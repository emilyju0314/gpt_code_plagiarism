ts::Time ts::TOT::localTime(const Region& reg) const
{
    // Add local time offset in milliseconds
    return utc_time + MilliSecond(reg.time_offset) * 60 * MilliSecPerSec;
}