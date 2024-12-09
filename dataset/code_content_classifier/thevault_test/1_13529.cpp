void Task::setBranch(GstElement* branch) throw()
{
    Locker lock(&m_lock);
    if (branch == m_branch)
        return; // nothing to do
    if (branch == NULL)
    {
        KLKASSERT(m_branch != NULL);
        gst_object_unref(GST_OBJECT(m_branch));
        m_branch = NULL;
    }
    else
    {
        m_branch = branch;
        gst_object_ref(GST_OBJECT(m_branch));
    }
}