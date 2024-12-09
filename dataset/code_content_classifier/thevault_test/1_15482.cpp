OGRErr MIFFile::GetExtent (OGREnvelope *psExtent, int bForce)
{
    if (bForce == TRUE)
        PreParseFile();

    if (m_bPreParsed)
    {
        *psExtent = m_sExtents;
        return OGRERR_NONE;
    }
    else
        return OGRERR_FAILURE;
}