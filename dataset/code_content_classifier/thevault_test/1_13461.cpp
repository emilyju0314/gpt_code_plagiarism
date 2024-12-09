const std::string Streamer::getOutRoute()
{
    BOOST_ASSERT(getAppUUID().empty() == false);
    // retrive application info
    db::DB db(getFactory());
    db.connect();

    //`klk_app_http_streamer_get` (
    // IN application VARCHAR(40),
    // OUT out_route VARCHAR(40)
    db::Parameters params;
    params.add("@application", getAppUUID());
    params.add("@route");
    params.add("@return_value");

    db::Result res = db.callSimple("klk_app_http_streamer_get", params);
    if (res["@return_value"].toInt() != 0)
    {
        throw Exception(__FILE__, __LINE__,
                        "Error while retrive info for HTTP streeamer "
                        "from db");
    }

    return res["@route"].toString();
}