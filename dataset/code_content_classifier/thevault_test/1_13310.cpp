void BaseBranchFactory::createMuxAudio()
{
    BOOST_ASSERT(m_mux);
    if (gst_element_set_state (GST_ELEMENT(m_mux), GST_STATE_PAUSED) ==
        GST_STATE_CHANGE_FAILURE)
    {
        throw Exception(__FILE__, __LINE__,
                        "gst_element_set_state() was failed");
    }

    GstPad *lame_pad = getAudioMuxPad();
    BOOST_ASSERT(lame_pad);
    GstPad* a_mux_pad = gst_ghost_pad_new ("sink_audio", lame_pad);
    BOOST_ASSERT(a_mux_pad);
    gst_pad_set_active(a_mux_pad, TRUE);
    if (!gst_element_add_pad (m_mux, a_mux_pad))
    {
        throw Exception(__FILE__, __LINE__,
                        "gst_element_add_pad() was failed");
    }
    gst_object_unref (lame_pad);
}