static void disconnect(const StreamType &stream_type)
{
    std::string uri1;
    std::string uri2;
    switch (stream_type)
    {
        case StreamType::RAW:
            uri1 = raw_udp_context.uri;
            uri2 = raw_tcp_context.uri;
            break;
        case StreamType::RESULT:
            uri1 = result_udp_context.uri;
            uri2 = result_tcp_context.uri;
            break;
        case StreamType::H264_RAW:
            uri1 = h264_context.uri;
            uri2 = h264_context.uri; // hack to make the rest of the function nice
            break;
        default:
            util::log_error("Cannot disconnect from unknown stream.");
            assert(false);
            return;
    }

    // Remove the factory from the mount point so that no one else can connect to its URI
    auto server = raw_udp_context.server; // All the server pointers are the same, so it doesn't matter which context
    GstRTSPMountPoints *mounts = gst_rtsp_server_get_mount_points(server);
    gst_rtsp_mount_points_remove_factory(mounts, uri1.c_str());
    gst_rtsp_mount_points_remove_factory(mounts, uri2.c_str());
    g_object_unref(mounts);

    // Remove existing clients
    gst_rtsp_server_client_filter(server, client_filter, nullptr);
}