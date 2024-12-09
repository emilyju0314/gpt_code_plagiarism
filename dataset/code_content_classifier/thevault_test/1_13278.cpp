void Transcode::doSchedulePlayback()
{
    // first of all we should stop tasks
    TaskInfoList stop_list = getStopList();

    // stop affected pipelines
    m_scheduler.pausePipelines(stop_list);
    std::for_each(stop_list.begin(), stop_list.end(),
                  boost::bind(&Transcode::deinitInfo,
                              this, _1));
    // start processing affected pipelines
    m_scheduler.playPipelines(stop_list);

    TaskInfoList start_list = getStartList();

    // stop affected pipelines
    m_scheduler.pausePipelines(start_list);

    // tasks container updates
    // it will also start all new threads
    // and stops threads that currently not active
    std::for_each(start_list.begin(), start_list.end(),
                  boost::bind(&Transcode::initTask,
                              this, _1));

    // start processing affected pipelines
    m_scheduler.playPipelines(start_list);
}