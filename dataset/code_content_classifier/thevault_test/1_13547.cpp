void Thread::setState(GstState state)
{
    Element pipeline(getPipeline());
    if (gst_element_set_state (GST_ELEMENT(pipeline.getElement()),
                               state) == GST_STATE_CHANGE_FAILURE)
    {
        if (!isStopped())
        {
            addEvent(ERROR);
        }
        throw Exception(__FILE__, __LINE__,
                        "gst_element_set_state() was failed");
    }
}