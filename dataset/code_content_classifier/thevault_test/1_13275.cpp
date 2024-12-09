void Transcode::deinitInfo(const mod::InfoPtr& info) throw()
{
    try
    {
        m_scheduler.delTask(mod::Info::dynamicPointerCast<TaskInfo>(info));
    }
    catch(const std::exception& err)
    {
        klk_log(KLKLOG_ERROR,
                "Exception during transcode task deinitialization. "
                "Task name: %s."
                "Error description: %s",
                info->getName().c_str(), err.what());
    }
    catch(...)
    {
        klk_log(KLKLOG_ERROR,
                "Exception during transcode task deinitialization. "
                "Task name: %s.",
                info->getName().c_str());
    }
}