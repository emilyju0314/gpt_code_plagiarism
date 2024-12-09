int MIFFile::GetFeatureCountByType(int &numPoints, int &numLines,
                                   int &numRegions, int &numTexts,
                                   GBool bForce )
{
    if( m_bPreParsed || bForce )
    {
        PreParseFile();

        numPoints = m_nPoints;
        numLines = m_nLines;
        numRegions = m_nRegions;
        numTexts = m_nTexts;
        return 0;
    }
    else
    {
        numPoints = numLines = numRegions = numTexts = 0;
        return -1;
    }
}