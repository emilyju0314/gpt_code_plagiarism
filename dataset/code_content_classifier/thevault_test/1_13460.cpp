const Streamer::InfoSet Streamer::getInputInfoFromDB()
{
    BOOST_ASSERT(getAppUUID().empty() == false);

    // retrive application info
    db::DB db(getFactory());
    db.connect();

    //`klk_app_http_streamer_route_get` (
    // IN application VARCHAR(40)
    db::Parameters params;
    params.add("@application", getAppUUID());

    db::ResultVector rv =
        db.callSelect("klk_app_http_streamer_route_get", params, NULL);
    InfoSet set;
    for (db::ResultVector::iterator res = rv.begin();
         res != rv.end(); res++)
    {
        // SELECT
        // klk_app_http_streamer_route.in_route,
        // klk_app_http_streamer_route.out_path,
        // klk_media_types.name,
        // klk_app_http_streamer_media_types.uuid

        const std::string uuid = (*res)["in_route"].toString();
        // FIXME!!! complex code
        // getInfoByUUID throws an exception in the case of info not found
        try
        {
            InputInfoPtr find = m_info.getInfoByUUID(uuid);
            set.insert(find);
            continue;
        }
        catch(...)
        {
            // we have to add the new element
            // first of all we should get route info from network module
            try
            {
                InputInfoPtr info(new InputInfo(getRouteInfoByUUID(uuid)));
                info->setPath((*res)["out_path"].toString());
                info->setMediaTypeName((*res)["name"].toString());
                info->setMediaTypeUuid((*res)["uuid"].toString());
                set.insert(info);
                klk_log(KLKLOG_DEBUG, "Add an input HTTP route for start: "
                        "%s on %s:%d",
                        info->getRouteInfo()->getName().c_str(),
                        info->getRouteInfo()->getHost().c_str(),
                        info->getRouteInfo()->getPort());
            }
            catch(const std::exception& err)
            {
                klk_log(KLKLOG_ERROR, "Error while getting input routes: %s",
                        err.what());
            }
            catch(...)
            {
                klk_log(KLKLOG_ERROR,
                        "Error while getting input routes: unknown");
            }
        }
    }

    return set;
}