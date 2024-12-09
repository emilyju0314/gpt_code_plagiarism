gjNetwork::gjCall* gjNetwork::__CheckCall(const std::string& sInfo)
{
    // search callback object and compare info string
    FOR_EACH(it, m_apCall)
    {
        if((*it)->GetInfo() == sInfo)
            return (*it);
    }

    return NULL;
}