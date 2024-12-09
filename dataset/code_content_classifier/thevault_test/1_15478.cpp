void MIFFile::UpdateExtents(double dfX, double dfY)
{
    if (m_bExtentsSet == FALSE)
    {
        m_bExtentsSet = TRUE;
        m_sExtents.MinX = m_sExtents.MaxX = dfX;
        m_sExtents.MinY = m_sExtents.MaxY = dfY;
    }
    else
    {
        if (dfX < m_sExtents.MinX)
            m_sExtents.MinX = dfX;
        if (dfX > m_sExtents.MaxX)
          m_sExtents.MaxX = dfX;
        if (dfY < m_sExtents.MinY)
          m_sExtents.MinY = dfY;
        if (dfY > m_sExtents.MaxY)
          m_sExtents.MaxY = dfY;
    }
}