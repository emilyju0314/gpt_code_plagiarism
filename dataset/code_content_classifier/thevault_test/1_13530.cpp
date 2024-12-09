gst::Element Task::getBranch()
{
    Locker lock(&m_lock);
    if (m_branch == NULL)
    {
        // should be set before the call
        throw Exception(__FILE__, __LINE__,
                        "Branch has not been initialized");
    }
    if (!GST_IS_ELEMENT(m_branch))
    {
        throw Exception(__FILE__, __LINE__,
                        "Transcode branch is not a GstElement");
    }

    return gst::Element(m_branch);
}