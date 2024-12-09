bool CODK_CpuReadData::CheckS7DTL(const ODK_DTL& dtl)
{
	// year
    if (1970 > dtl.Year  ||  2262 < dtl.Year)
    {
        return false;
    }
    // month
    if (1 > dtl.Month  ||  12 < dtl.Month)
    {
        return false;
    }
    // day
    if (1 > dtl.Day  ||  31 < dtl.Day)
    {
        return false;
    }
    // weekday
    if (1 > dtl.Weekday  ||  7 < dtl.Weekday)
    {
        return false;
    }
    // hour
    if (23 < dtl.Hour)
    {
        return false;
    }
    // minute
    if (59 < dtl.Minute)
    {
        return false;
    }
    // second
    if (59 < dtl.Second)
    {
        return false;
    }
    // nanosecond
    if (999999999 < dtl.Nanosecond)
    {
        return false;
    }

    return true;
}