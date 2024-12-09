static void configure_stream_h264(GstRTSPMediaFactory *factory, GstRTSPMedia *media, gpointer user_data)
{
    // Hook up the two ends of the pipeline
    GstElement *media_element = gst_rtsp_media_get_element(media);
    GstElement *proxysrc = gst_bin_get_by_name_recurse_up(GST_BIN(media_element), h264_proxy_src_name.c_str());
    GstElement *proxysink = gst_bin_get_by_name_recurse_up(GST_BIN(h264_pipeline_stub), h264_proxy_sink_name.c_str());
    g_object_set(proxysrc, "proxysink", proxysink, nullptr);

    // Set the pipeline to PLAY
    GstStateChangeReturn ret = gst_element_set_state(h264_pipeline_stub, GST_STATE_PLAYING);
    if (ret == GST_STATE_CHANGE_FAILURE)
    {
        util::log_error("Could not start playing the H.264 streaming source pipeline. H.264 stream will not be available.");
        return;
    }

    // Set up the pipeline to start accepting data
    h264_pipeline_go = true;

    // Get our parameters from the user data
    StreamParameters *params = (StreamParameters *)user_data;

    // Need to create a new context for each new stream's need-data callback. Otherwise you can only ever have one client ever.
    std::vector<StreamParametersH264 *> contexts = {g_new0(StreamParametersH264, 1), g_new0(StreamParametersH264, 1)};
    for (auto &new_context : contexts)
    {
        new_context->params.enabled = params->enabled;
        new_context->params.resolution = params->resolution;
        new_context->params.fps = params->fps;
        new_context->params.stream_type = params->stream_type;
        new_context->params.name = params->name;
        new_context->params.uri = params->uri;
        new_context->params.server = params->server;
        new_context->first_frame_processed = FALSE;
        new_context->base_timestamp = 0;
        new_context->factory_clock = gst_rtsp_media_factory_get_clock(factory);
        g_object_set_data_full(G_OBJECT(media_element), "extra-data", new_context, (GDestroyNotify)g_free);
    }

    // Get the appsrc for this factory and hook up its need-data and enough-data callbacks.
    GstElement *appsrc = gst_bin_get_by_name_recurse_up(GST_BIN(h264_pipeline_stub), params->name.c_str());
    params->appsrc_need_data_signal_handle = g_signal_connect(appsrc, "need-data", (GCallback)need_data_callback_h264, contexts[0]);
    g_signal_connect(appsrc, "enough-data", (GCallback)enough_data_callback_h264, contexts[1]);
}