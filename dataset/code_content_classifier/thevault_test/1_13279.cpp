const TaskInfoList Transcode::getStopList() const
{
    TaskInfoList full = m_info.getInfoList();
    TaskInfoList result;
    for (TaskInfoList::iterator i = full.begin(); i != full.end(); i++)
    {
        TaskInfoPtr task = *i;
        if (task->isExperied())
        {
            result.push_back(task);
        }
    }

    return result;
}