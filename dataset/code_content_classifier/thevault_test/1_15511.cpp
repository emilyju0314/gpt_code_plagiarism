int TABFile::SetQuickSpatialIndexMode(GBool bQuickSpatialIndexMode/*=TRUE*/)
{
    if (m_eAccessMode != TABWrite || m_poMAPFile == NULL)
    {
        CPLError(CE_Failure, CPLE_AssertionFailed,
                 "SetQuickSpatialIndexMode() failed: file not opened for write access.");
        return -1;
    }


    return m_poMAPFile->SetQuickSpatialIndexMode(bQuickSpatialIndexMode);
}