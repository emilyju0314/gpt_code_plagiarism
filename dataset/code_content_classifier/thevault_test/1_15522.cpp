int TABFile::SetProjInfo(TABProjInfo *poPI)
{
    if (m_eAccessMode != TABWrite)
    {
        CPLError(CE_Failure, CPLE_NotSupported,
                 "SetProjInfo() can be used only with Write access.");
        return -1;
    }

    /*-----------------------------------------------------------------
     * Check that dataset has been created but no feature set yet.
     *----------------------------------------------------------------*/
    if (m_poMAPFile && m_nLastFeatureId < 1)
    {
        if (m_poMAPFile->GetHeaderBlock()->SetProjInfo( poPI ) != 0)
            return -1;
    }
    else
    {
        CPLError(CE_Failure, CPLE_AssertionFailed,
                 "SetProjInfo() can be called only after dataset has been "
                 "created and before any feature is set.");
        return -1;
    }

    /*-----------------------------------------------------------------
     * Lookup default bounds and reset m_bBoundsSet flag
     *----------------------------------------------------------------*/
    double dXMin, dYMin, dXMax, dYMax;

    m_bBoundsSet = FALSE;
    if (MITABLookupCoordSysBounds(poPI, dXMin, dYMin, dXMax, dYMax) == TRUE)
    {
        SetBounds(dXMin, dYMin, dXMax, dYMax);
    }

    return 0;
}