void Task::setPause()
{
    // update running time
    {
        Locker lock(&m_lock);
        m_running_time += getRunningTime(m_branch);
    }

    gst::Element branch(getBranch());
    if (gst_element_set_state (GST_ELEMENT(branch.getElement()),
                               GST_STATE_PAUSED) == GST_STATE_CHANGE_FAILURE)
    {
        throw Exception(__FILE__, __LINE__,
                        "gst_element_set_state() was failed");
    }
}