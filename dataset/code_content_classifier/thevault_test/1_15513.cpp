int TABFile::GetNextFeatureId_Spatial(int nPrevId)
{
    if (m_eAccessMode != TABRead)
    {
        CPLError(CE_Failure, CPLE_NotSupported,
            "GetNextFeatureId_Spatial() can be used only with Read access.");
        return -1;
    }

    if( m_poMAPFile == NULL )
    {
        CPLError(CE_Failure, CPLE_NotSupported,
            "GetNextFeatureId_Spatial() requires availability of .MAP file." );
        return -1;
    }

    return m_poMAPFile->GetNextFeatureId( nPrevId );
}