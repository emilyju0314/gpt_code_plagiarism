void ExcaliburFemClient::mpx3TestPulseEnableSet(unsigned int aChipId, unsigned int aEnable)
{
  // If chip ID = 0, loop over all chips and call this function recursively
  if (aChipId == 0)
  {

    for (unsigned int iChip = 1; iChip <= kNumAsicsPerFem; iChip++)
    {
      this->mpx3TestPulseEnableSet(iChip, aEnable);
    }
  }
  else
  {
    // Internal chip index runs from 0 to 7
    unsigned int chipIdx = aChipId - 1;

    mMpx3OmrParams[chipIdx].testPulseEnable = aEnable;
  }

}