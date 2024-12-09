const StringList
TaskAddCommand::getVideoQualityList()
{
    StringList list;

    // klk_app_transcode_video_quality_list
    //SELECT klk_app_transcode_video_quality.quality_name AS name,

    db::DB db(getFactory());
    db.connect();

    db::Parameters dbparams;

    db::ResultVector rv = db.callSelect("klk_app_transcode_video_quality_list",
                                        dbparams, NULL);
    for (db::ResultVector::iterator item = rv.begin();
         item != rv.end(); item++)
    {
        list.push_back((*item)["name"].toString());
    }

    return list;
}