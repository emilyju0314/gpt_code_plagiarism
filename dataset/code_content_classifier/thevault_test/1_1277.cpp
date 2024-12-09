mpx3Dac ExcaliburFemClient::mpx3DacIdGet(int aId)
{
  // Set default resolved ID to unknown DAC
  mpx3Dac resolvedId = unknownDacId;

  // Static STL map to store mapping from API DAC IDs to internal.
  // If map is empty (i.e. at first call to this function, initialise
  // the values.
  static std::map<int, mpx3Dac> dacMap;
  if (dacMap.empty())
  {
    dacMap[FEM_OP_MPXIII_THRESHOLD0DAC] = threshold0Dac;
    dacMap[FEM_OP_MPXIII_THRESHOLD1DAC] = threshold1Dac;
    dacMap[FEM_OP_MPXIII_THRESHOLD2DAC] = threshold2Dac;
    dacMap[FEM_OP_MPXIII_THRESHOLD3DAC] = threshold3Dac;
    dacMap[FEM_OP_MPXIII_THRESHOLD4DAC] = threshold4Dac;
    dacMap[FEM_OP_MPXIII_THRESHOLD5DAC] = threshold5Dac;
    dacMap[FEM_OP_MPXIII_THRESHOLD6DAC] = threshold6Dac;
    dacMap[FEM_OP_MPXIII_THRESHOLD7DAC] = threshold7Dac;
    dacMap[FEM_OP_MPXIII_PREAMPDAC] = preampDac;
    dacMap[FEM_OP_MPXIII_IKRUMDAC] = ikrumDac;
    dacMap[FEM_OP_MPXIII_SHAPERDAC] = shaperDac;
    dacMap[FEM_OP_MPXIII_DISCDAC] = discDac;
    dacMap[FEM_OP_MPXIII_DISCLSDAC] = discLsDac;
    dacMap[FEM_OP_MPXIII_SHAPERTESTDAC] = shaperTestDac;
    dacMap[FEM_OP_MPXIII_DISCLDAC] = discLDac;
    dacMap[FEM_OP_MPXIII_DELAYDAC] = delayDac;
    dacMap[FEM_OP_MPXIII_TPBUFFERINDAC] = tpBufferInDac;
    dacMap[FEM_OP_MPXIII_TPBUFFEROUTDAC] = tpBufferOutDac;
    dacMap[FEM_OP_MPXIII_RPZDAC] = rpzDac;
    dacMap[FEM_OP_MPXIII_GNDDAC] = gndDac;
    dacMap[FEM_OP_MPXIII_TPREFDAC] = tpRefDac;
    dacMap[FEM_OP_MPXIII_FBKDAC] = fbkDac;
    dacMap[FEM_OP_MPXIII_CASDAC] = casDac;
    dacMap[FEM_OP_MPXIII_TPREFADAC] = tpRefADac;
    dacMap[FEM_OP_MPXIII_TPREFBDAC] = tpRefBDac;
    dacMap[FEM_OP_MPXIII_TESTDAC] = testDac;
    dacMap[FEM_OP_MPXIII_DISCHDAC] = discHDac;
  }

  // Check if the DAC ID is present in the map. If so, resolve
  // to the internal value.
  if (dacMap.count(aId))
  {
    resolvedId = dacMap[aId];
  }

  return resolvedId;
}