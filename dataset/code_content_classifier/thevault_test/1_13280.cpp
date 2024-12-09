const TaskInfoList Transcode::getStartList() const
{
    // original list
    TaskInfoList full = m_info.getInfoList();
    TaskInfoList result;
    for (TaskInfoList::iterator task = full.begin(); task != full.end(); task++)
    {
        if ((*task)->needStart())
            result.push_back(*task);
    }

    return result;
}