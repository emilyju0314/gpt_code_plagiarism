void CouplingIterationInterface::beginIteration(AdaptInfo& adaptInfo)
  {
    FUNCNAME("CouplingIterationInterface::beginIteration()");
    MSG("\n");
    int nTimesteps = (adaptInfo.getNumberOfTimesteps()
                      ? adaptInfo.getNumberOfTimesteps()
                      : static_cast<int>((adaptInfo.getEndTime()-adaptInfo.getStartTime())/adaptInfo.getTimestep())
                     );
    MSG("begin of iteration number: %d/%d\n",
        adaptInfo.getTimestepNumber() + 1,
        nTimesteps);
    MSG("==================================================\n");
  }