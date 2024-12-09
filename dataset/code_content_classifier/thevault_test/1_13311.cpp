void BaseBranchFactory::createMuxVideo()
{
    BOOST_ASSERT(m_mux);
    if (gst_element_set_state (GST_ELEMENT(m_mux), GST_STATE_PAUSED) ==
        GST_STATE_CHANGE_FAILURE)
    {
        throw Exception(__FILE__, __LINE__,
                        "gst_element_set_state() was failed");
    }

    GstPad *flutsmux_pad = getVideoMuxPad();
    BOOST_ASSERT(flutsmux_pad);
    GstPad* v_mux_pad = gst_ghost_pad_new ("sink_video", flutsmux_pad);
    BOOST_ASSERT(v_mux_pad);
    gst_pad_set_active(v_mux_pad, TRUE);
    if (!gst_element_add_pad (m_mux, v_mux_pad))
    {
        throw Exception(__FILE__, __LINE__,
                        "gst_element_add_pad() was failed");
    }
    gst_object_unref (flutsmux_pad);
}