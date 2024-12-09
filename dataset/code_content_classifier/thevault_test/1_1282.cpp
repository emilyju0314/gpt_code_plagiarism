void ExcaliburFemClient::mpx3GainModeSet(unsigned int aGainMode)
{

  // Set value in OMR parameter block for all chips
  for (unsigned int iChipIdx = 0; iChipIdx < kNumAsicsPerFem; iChipIdx++)
  {
    mMpx3OmrParams[iChipIdx].gainMode = (mpx3GainMode) aGainMode;
  }

}