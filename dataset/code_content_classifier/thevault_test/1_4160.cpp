inline unsigned int GetTargetSpacing()
{
    if (fTestNet)
        return nTargetSpacing2;

    else if (pindexBest->nHeight <= PoSFixHeight)
      return nTargetSpacing;
    else if (pindexBest->nHeight <= BlocktimeOneMinHeight)
      return nTargetSpacing2;
    else
      return nTargetSpacing3;
}