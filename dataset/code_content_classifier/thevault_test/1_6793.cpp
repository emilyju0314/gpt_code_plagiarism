SctpDest_S*  SctpCMTAgent::SelectFromPFDests()
{
  
  int iLeastErrorCount = (int) uiPathMaxRetrans; 
  double dMostRecentPFSince = 0; 
  Node_S *spCurrDestNode = NULL;
  SctpDest_S* spCurrDestNodeData = NULL;
  SctpDest_S* spSelectedDest = NULL;
  
  for(spCurrDestNode = sDestList.spHead;
      spCurrDestNode != NULL;
      spCurrDestNode = spCurrDestNode->spNext)
    { 
      spCurrDestNodeData = (SctpDest_S *) spCurrDestNode->vpData;
      
      if (spCurrDestNodeData->eStatus == SCTP_DEST_STATUS_POSSIBLY_FAILED)
	{
	  if (spCurrDestNodeData->iErrorCount < iLeastErrorCount) 
	    {
	      spSelectedDest = spCurrDestNodeData;
	      iLeastErrorCount = spCurrDestNodeData->iErrorCount;
	      dMostRecentPFSince = spCurrDestNodeData->dPFSince;
	    }
	  else if (spCurrDestNodeData->iErrorCount == iLeastErrorCount)
	    {
	      if (spCurrDestNodeData->dPFSince > dMostRecentPFSince)
		{
		  spSelectedDest = spCurrDestNodeData;
		  iLeastErrorCount = spCurrDestNodeData->iErrorCount;
		  dMostRecentPFSince = spCurrDestNodeData->dPFSince;
		}
	      else if (spCurrDestNodeData->dPFSince == dMostRecentPFSince)
		{
		  if (Random::random()&01)
		    spSelectedDest = spCurrDestNodeData;
		}
	    } 
	  
	} 
      else 
	{
	  /* Found a non-PF dest, return NULL 
	   */
	  return NULL;
	  
	}
      
    } 

  /* A PF destination was selected to be marked Active
   */
  if (spSelectedDest->eRtxTimerIsRunning == TRUE)
    StopT3RtxTimer(spSelectedDest);
  
  spSelectedDest->opHeartbeatTimeoutTimer->force_cancel();
  spSelectedDest->eHBTimerIsRunning = FALSE;
  
  spSelectedDest->iCwnd = 1*uiMaxDataSize;
  
  spSelectedDest->eStatus = SCTP_DEST_STATUS_ACTIVE;
  spSelectedDest->dPFSince = 0;
  
  //  DBG_PL(SelectFromPFDests, "Dest: %p changed from PF to Active"),
  // spSelectedDest  DBG_PR;
  
  return spSelectedDest;

}