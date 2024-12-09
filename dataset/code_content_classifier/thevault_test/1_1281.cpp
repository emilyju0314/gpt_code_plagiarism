void ExcaliburFemClient::mpx3CsmSpmModeSet(unsigned int aCsmSpmMode)
{

  // Set value in OMR parameter block for all chips
  for (unsigned int iChipIdx = 0; iChipIdx < kNumAsicsPerFem; iChipIdx++)
  {
    mMpx3OmrParams[iChipIdx].csmSpmMode = (mpx3CsmSpmMode) aCsmSpmMode;
  }

}