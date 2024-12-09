GstClockTime Task::getRunningTime(GstElement* branch)
{
    GstClockTime result = 0ULL;
    if (branch)
    {
        GstClock *clock = gst_element_get_clock(branch);
        if (clock)
        {
            result = gst_clock_get_time(clock) -
                gst_element_get_base_time(branch);
            gst_object_unref(clock);
        }
    }
    return result;
}