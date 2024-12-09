GstElement*  BaseBranchFactory::createVideoBin() const
{
    GstElement * vsinkbin = gst_bin_new (NULL);

    g_object_set (G_OBJECT (vsinkbin), "name", "videobin", NULL);

    GstElement* queue = makeQueue();
    BOOST_ASSERT(queue);
    GstElement* cspace = gst_element_factory_make ("ffmpegcolorspace", NULL);
    BOOST_ASSERT(cspace);

    GstElement* deinterlace = gst_element_factory_make ("ffdeinterlace", NULL);
    if ( !deinterlace)
    {
        klk_log(KLKLOG_DEBUG, "ffdeinterlace missing");
        deinterlace = gst_element_factory_make ("deinterlace", NULL);
    }
    BOOST_ASSERT(deinterlace);

    GstElementVector vscale = getVScale();
    BOOST_ASSERT(m_vquality);
    GstElement* encoder = createVideoEncoder(m_vquality->getQuality());
    BOOST_ASSERT(encoder);

    GstElement *identity = gst_element_factory_make ("identity", "identity");
    BOOST_ASSERT(identity);
    g_object_set (G_OBJECT (identity), "sync", TRUE, NULL);

    // different elements in the bin for default video scale and not
    // FIXME!!! same code at theorabranchfactory
    if (vscale.size() == 2)
    {
        BOOST_ASSERT(vscale[0]);
        BOOST_ASSERT(vscale[1]);
        gst_bin_add_many(GST_BIN (vsinkbin), queue, identity,
                         cspace, deinterlace,
                         vscale[0], vscale[1], encoder, NULL);
        if ( gst_element_link_many (queue, identity, cspace,
                                    vscale[0], vscale[1], deinterlace,
                                    encoder, NULL) != TRUE)
        {
            throw Exception(__FILE__, __LINE__,
                            "gst_element_link_many () failed");
        }
    }
    else
    {
        gst_bin_add_many(GST_BIN (vsinkbin), queue, identity,
                         cspace, deinterlace, encoder, NULL);
        if ( gst_element_link_many (queue, identity, cspace,
                                    deinterlace, encoder, NULL) != TRUE)
        {
            throw Exception(__FILE__, __LINE__,
                            "gst_element_link_many () failed");
        }
    }

    GstPad * videopad = gst_element_get_pad (queue, "sink");
    GstPad* ghost_sink = gst_ghost_pad_new ("sink", videopad);
    gst_object_unref (videopad);
    gboolean bres = gst_element_add_pad (vsinkbin, ghost_sink);
    BOOST_ASSERT(bres == TRUE);

    GstPad *encoder_pad = gst_element_get_pad (encoder, "src");
    GstPad* ghost_src = gst_ghost_pad_new ("src", encoder_pad);
    //gst_object_unref (encoder_pad);
    bres = gst_element_add_pad (vsinkbin, ghost_src);
    BOOST_ASSERT(bres == TRUE);

    return vsinkbin;
}