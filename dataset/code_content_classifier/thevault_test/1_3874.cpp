static void need_data_callback(GstElement *appsrc, guint unused, StreamParameters *params)
{
    // Feed out the buffer
    cv::Mat frame = get_frame(params->name);
    guint size = frame.size().width * frame.size().height * frame.channels();
    GstBuffer *buffer = gst_buffer_new_allocate(nullptr, size, nullptr);
    gst_buffer_fill(buffer, 0, frame.data, size);

    // Increment the timestamp.
    GST_BUFFER_PTS(buffer) = params->timestamp;
    GST_BUFFER_DURATION(buffer) = gst_util_uint64_scale_int(1, GST_SECOND, params->fps);
    params->timestamp += GST_BUFFER_DURATION(buffer);

    // Push the RGB frame into the pipeline
    GstFlowReturn ret;
    g_signal_emit_by_name(appsrc, "push-buffer", buffer, &ret);

    // Clean up after ourselves
    gst_buffer_unref(buffer);
}