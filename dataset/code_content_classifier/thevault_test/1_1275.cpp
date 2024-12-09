void ExcaliburFemClient::mpx3CtprWrite(unsigned int aChipId)
{

  // If chip ID = 0, loop over all chips and call this function recursively
  if (aChipId == 0)
  {
    for (unsigned int iChip = 1; iChip <= kNumAsicsPerFem; iChip++)
    {
      this->mpx3CtprWrite(iChip);
    }
  }
  else
  {
    // Internal chip index runs from 0 to 7
    unsigned int chipIdx = aChipId - 1;

    // Store CTPR values into u32 vector for upload to FEM
    std::vector<u32> ctprValues(kNumAsicDpmWords, 0);

    // Pack CTPR values into the words of the vector, starting with the rightmost column (255)
    // as the bits are loaded MSB first
    unsigned int wordIdx = 0;
    unsigned int bitIdx = 31;

    for (int iCol = (kNumColsPerAsic - 1); iCol >= 0; iCol--)
    {
      ctprValues[wordIdx] |= (mMpx3ColumnTestPulseEnable[chipIdx][iCol] & 1) << bitIdx;
      if (bitIdx == 0)
      {
        bitIdx = 31;
        wordIdx++;
      }
      else
      {
        bitIdx--;
      }
    }

    {
        std::ostringstream os;
        for (unsigned int iWord = 0; iWord < 8; iWord++)
        {
          os  << "0x" << std::hex << std::setw(8) << std::setfill('0') << ctprValues[iWord]
              << std::dec << " ";
        }
        FEMLOG(mFemId, logDEBUG) << "CTPR Chip: " << chipIdx << " " << os.str();
    }

    // Write DAC values into FEM (into DPM area accessed via RDMA)
    this->rdmaWrite(kExcaliburAsicDpmRdmaAddress, ctprValues);

    // Set ASIC MUX register
    this->asicControlMuxChipSelect(chipIdx);

    // Set OMR registers
    mpx3Omr theOmr = this->mpx3OMRBuild(chipIdx, setCtpr);
    this->asicControlOmrSet(theOmr);

    // Trigger OMR command write
    this->asicControlCommandExecute(asicCommandWrite);

  }
}