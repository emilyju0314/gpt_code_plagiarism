const StringList
TaskAddCommand::getVideoSizeList()
{
    StringList list;

    // klk_app_transcode_video_size_list
    //SELECT klk_app_transcode_video_size.size_name AS name,

    db::DB db(getFactory());
    db.connect();

    db::Parameters dbparams;

    db::ResultVector rv = db.callSelect("klk_app_transcode_video_size_list",
                                        dbparams, NULL);
    for (db::ResultVector::iterator item = rv.begin();
         item != rv.end(); item++)
    {
        list.push_back((*item)["name"].toString());
    }

    return list;
}