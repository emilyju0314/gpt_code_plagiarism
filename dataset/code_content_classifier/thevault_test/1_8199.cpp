void RFFEAnalyzer::GotoNextTransition() {
  U64 SclkEdgeSample;
  U64 SdataEdgeSample;

  // Store the previous Transition bus state
  mSclkPrevious = mSclkCurrent;
  mSdataPrevious = mSdataCurrent;

  // Look for a transition on SDATA without a clock transition
  SclkEdgeSample = mSclk->GetSampleOfNextEdge();
  SdataEdgeSample = mSdata->GetSampleOfNextEdge();

  if (SclkEdgeSample > SdataEdgeSample) {
    // Sclk is further out the sData
    mSamplePosition = SdataEdgeSample;
    mSclk->AdvanceToAbsPosition(SdataEdgeSample);
    mSdata->AdvanceToAbsPosition(SdataEdgeSample);
  } else {
    // Sdata transition is further out than Sclk
    mSamplePosition = SclkEdgeSample;
    mSclk->AdvanceToAbsPosition(SclkEdgeSample);
    mSdata->AdvanceToAbsPosition(SclkEdgeSample);
  }

  // Update the current transition bus state
  mSclkCurrent = mSclk->GetBitState();
  mSdataCurrent = mSdata->GetBitState();
}