int MIFFile::GotoFeature(int nFeatureId)
{

    if (nFeatureId < 1)
      return -1;

    if (nFeatureId == m_nPreloadedId) // CorrectPosition
    {
        return 0;
    }
    else
    {
        if (nFeatureId < m_nCurFeatureId || m_nCurFeatureId == 0)
            ResetReading();

        while(m_nPreloadedId < nFeatureId)
        {
            if (NextFeature() == FALSE)
              return -1;
        }

        CPLAssert(m_nPreloadedId == nFeatureId);

        return 0;
    }
}