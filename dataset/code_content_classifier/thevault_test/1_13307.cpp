const BaseBranchFactory::GstElementVector
BaseBranchFactory::getVScale() const
{
    BaseBranchFactory::GstElementVector result;

    BOOST_ASSERT(m_vquality);
    const std::string size = m_vquality->getSize();
    if (size == quality::video::SIZE_DEFAULT)
        return result; // nothing to do

    result.reserve(2);

    GstElement* scale = gst_element_factory_make ("videoscale", NULL);
    result.push_back(scale);
    GstElement* filter = gst_element_factory_make ("capsfilter", NULL);
    result.push_back(filter);

    // FIXME!!! bad code
    if (size == quality::video::SIZE_320_240)
    {
        g_object_set (G_OBJECT(filter), "caps",
                      gst_caps_new_simple( "video/x-raw-yuv",
                                           "width", G_TYPE_INT, 320,
                                           "height", G_TYPE_INT, 240,NULL),
                      NULL );
    }
    else if (size == quality::video::SIZE_640_480)
    {
        g_object_set (G_OBJECT(filter), "caps",
                      gst_caps_new_simple( "video/x-raw-yuv",
                                           "width", G_TYPE_INT, 640,
                                           "height", G_TYPE_INT, 480,NULL),
                      NULL );
    }
    else if (size == quality::video::SIZE_720_576)
    {
        g_object_set (G_OBJECT(filter), "caps",
                      gst_caps_new_simple( "video/x-raw-yuv",
                                           "width", G_TYPE_INT, 720,
                                           "height", G_TYPE_INT, 576,NULL),
                      NULL );
    }
    else
    {
        throw Exception(__FILE__, __LINE__, "Unknown video scale size. UUID: " + size);
    }

    return result;
}