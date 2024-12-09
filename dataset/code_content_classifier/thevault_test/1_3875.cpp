static void need_data_callback_h264(GstElement *appsrc, guint unused, StreamParametersH264 *params)
{
    // We can start feeding data in.
    h264_pipeline_go = true;
}