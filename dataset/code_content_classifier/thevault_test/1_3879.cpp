static void construct_stream_stub_h264()
{
    // Launch the simple little pipeline
    GError *err = nullptr;
    std::string launch_cmd = "";
    launch_cmd += "appsrc name=" + h264_context.name;
    launch_cmd += " ! proxysink name=" + h264_proxy_sink_name;
    h264_pipeline_stub = gst_parse_launch(launch_cmd.c_str(), &err);
    if (err != nullptr)
    {
        util::log_error("Error in launching the H.264 streaming stub. Error code: " + std::to_string(err->code) + "; Error message: " + err->message);
    }

    // Check for fatal errors
    if (h264_pipeline_stub == nullptr)
    {
        util::log_error("Could not launch the H.264 streaming pipeline. H.264 stream will not be available.");
        return;
    }

    // Set the caps for the appsrc
    GstElement *appsrc = gst_bin_get_by_name_recurse_up(GST_BIN(h264_pipeline_stub), h264_context.name.c_str());
    int width;
    int height;
    std::tie(height, width) = get_height_and_width(h264_context.resolution);
    auto fps = h264_context.fps;
    g_object_set(G_OBJECT(appsrc), "caps",
        gst_caps_new_simple("video/x-h264",
            "stream-format",    G_TYPE_STRING,     "byte-stream",
            "width",            G_TYPE_INT,        width,
            "height",           G_TYPE_INT,        height,
            "framerate",        GST_TYPE_FRACTION, fps, 1,
            nullptr),
        nullptr);

    // Make sure appsrc never blocks the main thread (which is the thread that pushes data to it)
    g_object_set(G_OBJECT(appsrc), "block", false, nullptr);

    // Ensure that we emit signals (we will hook up the signals when we connect a client to the pipeline)
    g_object_set(G_OBJECT(appsrc), "emit-signals", true, nullptr);

    // Clean up after ourselves
    gst_object_unref(appsrc);
}