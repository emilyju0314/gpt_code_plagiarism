void ExcaliburFemClient::mpx3ReadWriteModeSet(unsigned int aReadWriteMode)
{

  // Set value in OMR parameter block for all chips
  for (unsigned int iChipIdx = 0; iChipIdx < kNumAsicsPerFem; iChipIdx++)
  {
    mMpx3OmrParams[iChipIdx].readWriteMode = (mpx3ReadWriteMode) aReadWriteMode;
  }

}