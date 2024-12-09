void CouplingIterationInterface::endIteration(AdaptInfo& adaptInfo)
  {
    FUNCNAME("CouplingIterationInterface::endIteration()");
    MSG("\n");
    MSG("end of iteration number: %d\n",
        adaptInfo.getTimestepNumber() + 1);
    MSG("==================================================\n");
  }