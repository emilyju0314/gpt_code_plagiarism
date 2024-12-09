static void configure_stream(GstRTSPMediaFactory *factory, GstRTSPMedia *media, gpointer user_data)
{
    // Get our parameters from the user data
    StreamParameters *params = (StreamParameters *)user_data;

    // Get the appsrc for this factory
    GstElement *media_element = gst_rtsp_media_get_element(media);
    GstElement *appsrc = gst_bin_get_by_name_recurse_up(GST_BIN(media_element), params->name.c_str());

    // Tell appsrc that we will be dealing with a timestamped buffer
    gst_util_set_object_arg(G_OBJECT(appsrc), "format", "time");

    // Determine the width and height of the stream from its resolution.
    auto buffer = get_frame(params->name);
    int width = buffer.size().width;
    int height = buffer.size().height;

    // Configure the video's caps (capabilities)
    g_object_set(G_OBJECT(appsrc), "caps",
        gst_caps_new_simple("video/x-raw",
            "format",    G_TYPE_STRING,     "BGR",
            "width",     G_TYPE_INT,        width,
            "height",    G_TYPE_INT,        height,
            "framerate", GST_TYPE_FRACTION, params->fps, 1,
            nullptr),
        nullptr);

    // Need to create a new context for each new stream's need-data callback. Otherwise you can only ever have one client ever.
    auto new_context = g_new0(StreamParameters, 1);
    new_context->enabled = params->enabled;
    new_context->resolution = params->resolution;
    new_context->fps = params->fps;
    new_context->stream_type = params->stream_type;
    new_context->name = params->name;
    new_context->timestamp = 0;
    new_context->uri = params->uri;
    new_context->server = params->server;
    g_object_set_data_full(G_OBJECT(media_element), "extra-data", new_context, (GDestroyNotify)g_free);

    // We call this callback whenever we need a new buffer to feed out.
    params->appsrc_need_data_signal_handle = g_signal_connect(appsrc, "need-data", (GCallback)need_data_callback, new_context);
    new_context->appsrc_need_data_signal_handle = params->appsrc_need_data_signal_handle;

    // Clean up after ourselves
    gst_object_unref(appsrc);
    gst_object_unref(media_element);
}