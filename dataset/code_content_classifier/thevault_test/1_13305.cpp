GstElement* SimpleBaseBranchFactory::makeQueue()
{
    GstElement *queue = gst_element_factory_make ("queue", NULL);
    BOOST_ASSERT(queue);

    g_object_set (queue,
                  "max-size-time", static_cast<guint64>(300 * GST_SECOND),
                  "max-size-bytes", static_cast<guint64>(0),
                  "max-size-buffers", static_cast<guint64>(0), NULL);

    return queue;
}