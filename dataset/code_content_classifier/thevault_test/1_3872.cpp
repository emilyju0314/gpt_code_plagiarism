static gboolean custom_setup_rtpbin(GstRTSPMedia *media, GstElement *rtpbin)
{
    g_object_set(rtpbin, "ntp-time-source", 3 /* clock-time */, nullptr);

    // If clock sync seems off, uncommenting the below line might help. This will tell the RTP Manager to set the NTP
    // timestamp in the RTCP SR to the "capture" time rather than the "send" time. This might help when there is a delay
    // between the time the frame was captured and when it is actually sent.
    // g_object_set(rtpbin, "rtcp-sync-send-time", FALSE, nullptr);

    return TRUE;
}