void PU::fillIBCMvpCand( PredictionUnit &pu, AMVPInfo &amvpInfo, MotionHist& hist )
{

  AMVPInfo *pInfo = &amvpInfo;

  pInfo->numCand = 0;

  MergeCtx mergeCtx;
  PU::getIBCMergeCandidates(pu, mergeCtx, hist, AMVP_MAX_NUM_CANDS - 1);
  int candIdx = 0;
  while (pInfo->numCand < AMVP_MAX_NUM_CANDS)
  {
    pInfo->mvCand[pInfo->numCand] = mergeCtx.mvFieldNeighbours[(candIdx << 1) + 0].mv;;
    pInfo->numCand++;
    candIdx++;
  }

  for (Mv &mv : pInfo->mvCand)
  {
    mv.roundToPrecision( MV_PRECISION_INTERNAL, pu.imv() == 2 ? MV_PRECISION_4PEL : MV_PRECISION_INT );
  }
}