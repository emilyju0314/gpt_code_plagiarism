void BaseBranchFactory::onNewDecodedPad(GstElement *decodebin,
                                        GstPad     *new_pad,   gboolean    last,
                                        gpointer    user_data) throw()
    try
    {
        BaseBranchFactory *holder =
            static_cast<BaseBranchFactory*>(user_data);
        BOOST_ASSERT(holder);

        // set pipeline in pause mode
        holder->pausePipeline();

        GstCaps* caps = gst_pad_get_caps (new_pad);
        BOOST_ASSERT(caps);
        gchar* str = gst_caps_to_string (caps);
        BOOST_ASSERT(str);

        klk_log(KLKLOG_DEBUG, "GST: new_decoded_pad_cb () caps: %s", str);
        /* video stream */
        if (g_str_has_prefix (str, "video/"))
        {
            holder->createVideoSink(new_pad);
        }
        /* audio stream */
        else if (g_str_has_prefix (str, "audio/"))
        {
            holder->createAudioSink(new_pad);
        }
        // set pipeline in playing mode
        holder->playPipeline();
    }
    catch(const std::exception& err)
    {
        klk_log(KLKLOG_ERROR, "Error in new_decoded_pad_cb(): %s", err.what());
    }
    catch(...)
    {
        klk_log(KLKLOG_ERROR, "Error in new_decoded_pad_cb():"
                " unknow exception");
    }