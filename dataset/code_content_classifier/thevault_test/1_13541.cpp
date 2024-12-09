void HTTPSrcInfo::initInternal(Transcode* module)
{
    BOOST_ASSERT(module);
    IFactory* factory = module->getFactory();
    IMessageFactory* msgfactory = factory->getMessageFactory();
    IMessagePtr req = msgfactory->getMessage(msg::id::HTTPSRCSTART);
    BOOST_ASSERT(req);
    req->setData(msg::key::MODINFOUUID, getUUID());
    IMessagePtr res;
    module->sendSyncMessage(req, res);
    BOOST_ASSERT(res);
    if (res->getValue(msg::key::STATUS) != msg::key::OK)
    {
        // net module reject it
        throw Exception(__FILE__, __LINE__,
                        "HTTP source module rejected request. Name: %s, UUID: '%s'",
                        getName().c_str(),
                        getUUID().c_str());
    }

    const std::string addr = res->getValue(msg::key::HTTPSRC_ADDR);
    BOOST_ASSERT(!addr.empty());
    const std::string login = res->getValue(msg::key::HTTPSRC_LOGIN);
    const std::string pwd = res->getValue(msg::key::HTTPSRC_PWD);

    /*
      gst-launch -v souphttpsrc user-id=Login user-pw=Password location=http://nako-camera.no-ip.org:31080/video/mjpg.cgi?profileid=3 ! multipartdemux ! jpegdec name=d ffmux_flv name=mux ! tcpclientsink host=192.168.134.2 port=20001 d. ! queue ! ffmpegcolorspace ! "video/x-raw-yuv",format=\(fourcc\)I420 ! deinterlace ! videoscale ! "video/x-raw-yuv",width=320,height=240 ! ffenc_flv ! mux.
     */

    initElement("souphttpsrc", module->getFactory());
    g_object_set(G_OBJECT (m_element), "location", addr.c_str(), NULL);
    if (!login.empty())
    {
        g_object_set(G_OBJECT (m_element), "user-id", login.c_str(), NULL);
    }
    if (!pwd.empty())
    {
        g_object_set(G_OBJECT (m_element), "user-pw", pwd.c_str(), NULL);
    }
}