void ts::EITProcessor::addStartTimeOffet(MilliSecond offset, bool date_only)
{
    _start_time_offset = offset;
    _date_only = date_only;
}