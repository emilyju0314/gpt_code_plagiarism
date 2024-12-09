const Transcode::InfoSet Transcode::getTaskInfoFromDB()
{
    // read tasks by input sources

    // klk_app_transcode_get

    db::DB db(getFactory());
    db.connect();

    db::Parameters params;

    db::ResultVector rv = db.callSelect("klk_app_transcode_get",
                                        params, NULL);

    InfoSet set;
    for (db::ResultVector::iterator item = rv.begin();
         item != rv.end(); item++)
    {
        // Tasks specific

        // input source specific
        // input_source.source_uuid AS input_uuid,
        const std::string input_uuid = (*item)["input_uuid"].toString();
        // input_source.source_name AS input_name,
        const std::string input_name = (*item)["input_name"].toString();
        // input_source.source_type AS input_source_type,
        const std::string input_type =
            (*item)["input_source_type"].toString();
        // input_source.media_type AS input_media_type,
        const std::string input_media_type =
            (*item)["input_media_type"].toString();
        SourceInfoPtr input =
            m_source_factory.getSource(input_uuid, input_name, input_media_type,
                                       input_type);

        // output source specific
        // output_source.source_uuid AS output_uuid,
        const std::string output_uuid = (*item)["output_uuid"].toString();
        // output_source.source_name AS output_name,
        const std::string output_name = (*item)["output_name"].toString();
        // output_source.source_type AS output_source_type,
        const std::string output_type =
            (*item)["output_source_type"].toString();
        // output_source.media_type AS output_media_type,
        const std::string output_media_type =
            (*item)["output_media_type"].toString();

        SourceInfoPtr output =
            m_source_factory.getSource(output_uuid, output_name, output_media_type,
                                       output_type);

        // SELECT klk_app_transcode_task.task AS task_uuid,
        const std::string task_uuid = (*item)["task_uuid"].toString();
        // klk_app_transcode_task.task_name AS task_name,
        const std::string task_name = (*item)["task_name"].toString();


        // klk_app_transcode_video_size.size_uuid AS vsize_uuid,
        const std::string vsize =   (*item)["vsize_uuid"].toString();
        //klk_app_transcode_video_quality.quality_uuid AS vquality_uuid,
        const std::string vquality =   (*item)["vquality_uuid"].toString();
        quality::VideoPtr video_params(new quality::Video(vsize, vquality));

        // klk_app_transcode_task.schedule_start AS schedule_start,
        const std::string schedule_start =
            (*item)["schedule_start"].toString();
        // klk_app_transcode_task.schedule_duration AS schedule_duration
        const time_t schedule_duration =
            static_cast<time_t>((*item)["schedule_duration"].toInt());
        TaskInfoPtr task(new TaskInfo(task_uuid, task_name,
                                       input, output,
                                       video_params,
                                       schedule_start, schedule_duration));
        set.insert(task);
    }

    return set;
}