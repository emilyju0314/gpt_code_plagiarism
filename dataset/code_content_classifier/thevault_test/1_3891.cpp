static void update_time_alignment(bool align)
{
    if (update_time_alignment_cb == nullptr)
    {
        util::log_info("Attempting to update the time alignment feature before a callback function is set.");
        return;
    }

    // Update
    (*update_time_alignment_cb)(align);
}