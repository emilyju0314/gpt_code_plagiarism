void HD44780Analyzer::AdvanceToAbsPositionWhileMarking(AnalyzerChannelData *AACD, Channel AC, U64 APosition)
{
  if (APosition<=AACD->GetSampleNumber())
    return;

  while (mSettings->mMarkTimingErrors && AACD->WouldAdvancingToAbsPositionCauseTransition(APosition) && AACD->GetSampleOfNextEdge()<APosition)
    {
      AACD->AdvanceToNextEdge();
      mResults->AddMarker(AACD->GetSampleNumber(), AnalyzerResults::X, AC );
    }
  AACD->AdvanceToAbsPosition(APosition);
}