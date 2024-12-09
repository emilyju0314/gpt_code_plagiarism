static void configure_rtsp_stream_factory_h264(GstRTSPMediaFactory *factory, const std::string &appsrc_name, GstRTSPLowerTrans protocol, void *configure_stream_arg)
{
    // This is the GStreamer pipeline that will be created whenever someone connects to this factory's endpoint.
    // The H.264 pipeline is a little different from the other ones. It operates in a push mode rather than a pull mode.
    // This means that we use a pipeline like this:
    // appsrc -> proxysink => proxysrc -> h264 stuff -> RTSP stream
    // The appsrc -> proxysink part of the pipeline is always set up and ready to accept more H.264 frames from the
    // application, but the proxysrc -> h264 stuff -> RTSP stream part of the pipeline is not. It gets created and started
    // whenever a client connects to us looking for the H.264 stream. When that happens, we construct this half of the pipeline,
    // start it up, and let the appsrc know that it can start pushing buffers into the pipeline now.
    int width;
    int height;
    std::tie(height, width) = get_height_and_width(h264_context.resolution);
    int fps = h264_context.fps;
    auto caps = "video/x-h264,stream-format=(string)byte-stream,width=(int)" + std::to_string(width) + ",height=(int)" + std::to_string(height) +
                ",framerate=(fraction)" + std::to_string(fps) + "/1,alignment=(string)au";
    std::string gstreamer_cmd = "";
    gstreamer_cmd += "( proxysrc name=" + h264_proxy_src_name;  // Give it a name so that we can hook up the corresponding proxysink to it
    gstreamer_cmd += " ! " + caps;                              // Need to explicitly put the caps in, otherwise proxysrc doesn't know what's what
    gstreamer_cmd += " ! h264parse";                            // Interpret the bytestream buffers as H.264 frames
    gstreamer_cmd += " ! rtph264pay name=pay0 pt=96";           // Encode H.264-encoded video into RTSP packets
    gstreamer_cmd += " )";
    gst_rtsp_media_factory_set_launch(factory, gstreamer_cmd.c_str());

    // Use the appropriate protocol (TCP or UDP). We use TCP for AVA integration, though GStreamer complains that it is not
    // supported. Who knows?
    gst_rtsp_media_factory_set_protocols(factory, protocol);

    // Use our custom class, CustomClockRTSPMedia, rather than the regular GstRTSPMedia object.
    // A GstRTSPMedia object contains the entire gStreamer pipeline and is created by the factory when a client
    // issues a DESCRIBE or SETUP command.
    gst_rtsp_media_factory_set_media_gtype(factory, CUSTOM_CLOCK_RTSP_MEDIA_TYPE);

    // Create a system clock to be used by this factory only.
    GstClock *factory_system_clock = reinterpret_cast<GstClock *>(g_object_new(gst_system_clock_get_type(), nullptr));

    // Tell this factory to use the specified clock as the media clock. We will sync this clock
    // to the UTC time once we process our first packet.
    gst_rtsp_media_factory_set_clock(factory, factory_system_clock);

    // Release our reference to the clock. The factory owns it now.
    g_object_unref(factory_system_clock);

    // Share the same GStreamer pipeline for each new client connection, rather than creating a brand new one for each.
    gst_rtsp_media_factory_set_shared(factory, true);

    // Hook up the callback for whenever a client connects to the server and the factory creates a new GStreamer pipeline in response
    // We hook up to this factory's "media-configure" signal.
    g_signal_connect(factory, "media-configure", (GCallback)configure_stream_h264, configure_stream_arg);
}