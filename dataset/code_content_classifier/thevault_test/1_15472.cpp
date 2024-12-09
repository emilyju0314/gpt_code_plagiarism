int MIFFile::GetNextFeatureId(int nPrevId)
{
    if (m_eAccessMode != TABRead)
    {
        CPLError(CE_Failure, CPLE_NotSupported,
                 "GetNextFeatureId() can be used only with Read access.");
        return -1;
    }

    if (nPrevId <= 0 && m_poMIFFile->GetLastLine() != NULL)
        return 1;       // Feature Ids start at 1
    else if (nPrevId > 0 && m_poMIFFile->GetLastLine() != NULL)
        return nPrevId + 1;
    else
        return -1;

    return 0;
}