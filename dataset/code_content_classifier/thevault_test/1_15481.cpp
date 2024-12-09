int MIFFile::GetBounds(double &dXMin, double &dYMin, 
                       double &dXMax, double &dYMax,
                       GBool bForce /*= TRUE*/ )
{
    
    if (m_bBoundsSet == FALSE && bForce == FALSE)
    {
        return -1;
    }
    else if (m_bBoundsSet == FALSE)
    {
        PreParseFile();
    }

    if (m_bBoundsSet == FALSE)
    {
        return -1;
    }

    dXMin = m_dXMin;
    dXMax = m_dXMax;
    dYMin = m_dYMin;
    dYMax = m_dYMax;
    
    return 0;
}