int MIFFile::SetBounds(double dXMin, double dYMin, 
                       double dXMax, double dYMax)
{
    if (m_eAccessMode != TABWrite)
    {
        CPLError(CE_Failure, CPLE_NotSupported,
                 "SetBounds() can be used only with Write access.");
        return -1;
    }

    m_dXMin = dXMin;
    m_dXMax = dXMax;
    m_dYMin = dYMin;
    m_dYMax = dYMax;
    m_bBoundsSet = TRUE;
    
    return 0; 
}