bool
stream_check::run() const {
    GstElement* elem;
    gst_init(nullptr, nullptr);
    std::vector<stream_model> streams = (*cache)->get_valid_streams();

    if (not streams.size()) {
        LOG_WARN_("There were no valid streams to check. Cameradar will stop.", "stream_check");
        return false;
    }

    for (const auto& stream : streams) {
        GError* error = NULL;

        GstElement* pipeline =
            gst_parse_launch("rtspsrc name=source ! rtph264depay ! h264parse ! fakesink", &error);

        std::string location = "rtsp://";
        location += stream.username + ":" + stream.password + "@" + stream.address + ":" +
                    std::to_string(stream.port);
        if (pipeline == NULL) {
            LOG_ERR_("[" + stream.address + "] Can't configure pipeline", "stream_check");
            return false;
        } else {
            elem = gst_bin_get_by_name(GST_BIN(pipeline), "source");
            LOG_DEBUG_("Launching gstreamer check on rtsp://" + stream.username + ":" +
                           stream.password + "@" + stream.address + ":" +
                           std::to_string(stream.port),
                       "gstreamer check");
            g_object_set(G_OBJECT(elem), "location", location.c_str(), "latency", 20, NULL);

            if (gst_element_set_state(pipeline, GST_STATE_PLAYING) == GST_STATE_CHANGE_FAILURE) {
                LOG_ERR_(
                    "This stream is unaccessible with GStreamer, there must be a "
                    "configuration issue",
                    "stream_check");
                gst_object_unref(pipeline);
                stream_model invalidstream{
                    stream.address,   stream.port,         stream.username,  stream.password,
                    stream.route,     stream.service_name, stream.product,   stream.protocol,
                    "invalid stream", stream.path_found,   stream.ids_found, stream.thumbnail_path
                };
                (*cache)->update_stream(invalidstream);
                return false;
            }
            LOG_INFO_("[" + stream.address +
                          "] This stream is accessible and seems to be functional",
                      "stream_check");
        }
    }
    LOG_INFO_("All streams could be accessed with GStreamer", "stream_check");
    return true;
}