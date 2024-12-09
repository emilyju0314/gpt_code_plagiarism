void ExcaliburFemClient::mpx3EqualizationModeSet(unsigned int aEqualizationMode)
{

  // Set value in OMR parameter block for all chips
  for (unsigned int iChipIdx = 0; iChipIdx < kNumAsicsPerFem; iChipIdx++)
  {
    mMpx3OmrParams[iChipIdx].equalizationMode = (mpx3EqualizationMode) aEqualizationMode;
  }

}