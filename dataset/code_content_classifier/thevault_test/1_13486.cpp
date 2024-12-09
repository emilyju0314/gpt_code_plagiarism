const cli::ParameterVector
InputAddCommand::getCompletion(const cli::ParameterVector& setparams)
{
    cli::ParameterVector res;

    if (setparams.empty()) // route name
    {
        const StringList names = getRouteList();
        std::copy(names.begin(), names.end(),
                  std::back_inserter(res));
    }
    else if (setparams.size() == 1) // path
    {
        InputInfoList infos = getModule<Streamer>()->getInputInfo();
        const std::string route = setparams[0];
        // FIXME!!! seems that can not be more than 10000 paths assigned
        for (int i = 0; i < 10000; i++)
        {
            std::stringstream name;
            name << "/" << route; // /route_name
            if (i > 0)
            {
                name << i; // /route_name1, /route_name2 ...
            }

            InputInfoList::iterator find = std::find_if(
                infos.begin(), infos.end(),
                boost::bind<bool>(FindInputInfoByPath(), _1, name.str()));
            if (find == infos.end())
            {
                res.push_back(name.str());
                break;
            }
        }
    }
    else if (setparams.size() == 2) // media type
    {
        db::DB db(getFactory());
        db.connect();
        db::Parameters dbparams;
        db::ResultVector rv =
            db.callSelect("klk_app_http_streamer_media_type_list",
                          dbparams, NULL);
        for (db::ResultVector::iterator i = rv.begin(); i != rv.end(); i++)
        {
            // SELECT name
            const std::string name = (*i)["name"].toString();
            res.push_back(name);
        }
    }

    return res;
}