void ExcaliburFemClient::mpx3DiscCsmSpmSet(unsigned int aDiscCsmSpm)
{

  // Set value in OMR parameter block for all chips
  for (unsigned int iChipIdx = 0; iChipIdx < kNumAsicsPerFem; iChipIdx++)
  {
    mMpx3OmrParams[iChipIdx].discCsmSpm = (mpx3DiscCsmSpm) aDiscCsmSpm;
  }

}