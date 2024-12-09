void SctpCMTAgent::FastRtx()
{
  DBG_I(FastRtx);

  Node_S *spCurrDestNode = NULL;
  SctpDest_S *spCurrDestData = NULL;
  Node_S *spCurrBuffNode = NULL;
  SctpSendBufferNode_S *spCurrBuffData = NULL;

  /* be sure we clear all the eCcApplied flags before using them!
   */
  for(spCurrDestNode = sDestList.spHead;
      spCurrDestNode != NULL;
      spCurrDestNode = spCurrDestNode->spNext)
    {
      spCurrDestData = (SctpDest_S *) spCurrDestNode->vpData;
      spCurrDestData->eCcApplied = FALSE;

      /****** Begin CMT Change *******/
      /* JRI-TODO: Why do I need RTX_LIMIT_ZERO? Why not use LIMIT_CWND as
       * the default?
       */
      spCurrDestData->eRtxLimit = RTX_LIMIT_ZERO;
      /****** End CMT Change *******/
    }
  
  /* go thru chunks marked for rtx and cut back their ssthresh, cwnd, and
   * partial bytes acked. make sure we only apply congestion control once
   * per destination and once per window (ie, round-trip).
   */
  for(spCurrBuffNode = sSendBuffer.spHead;
      spCurrBuffNode != NULL;
      spCurrBuffNode = spCurrBuffNode->spNext)
    {
      spCurrBuffData = (SctpSendBufferNode_S *) spCurrBuffNode->vpData;

      /* If the chunk has been either marked for rtx or advanced ack, we want
       * to apply congestion control (assuming we didn't already).
       *
       * Why do we do it for advanced ack chunks? Well they were advanced ack'd
       * because they were lost. The ONLY reason we are not fast rtxing them is
       * because the chunk has run out of retransmissions (u-sctp). So we need
       * to still account for the fact they were lost... so apply congestion
       * control!
       */

      /****** Begin CMT Change *******/
      /* CMT: use per-destination uiRecover
       */
      if((spCurrBuffData->eMarkedForRtx != NO_RTX ||
	  spCurrBuffData->eAdvancedAcked == TRUE) &&
	 spCurrBuffData->spDest->eCcApplied == FALSE &&
	 spCurrBuffData->spChunk->uiTsn > spCurrBuffData->spDest->uiRecover)
	/****** End CMT Change *******/
	{ 
	  /* section 7.2.3 of rfc2960 (w/ implementor's guide) 
	   */
	  spCurrBuffData->spDest->iSsthresh 
	    = MAX(spCurrBuffData->spDest->iCwnd/2, 
		  iInitialCwnd * (int) uiMaxDataSize);
	  spCurrBuffData->spDest->iCwnd = spCurrBuffData->spDest->iSsthresh;
	  spCurrBuffData->spDest->iPartialBytesAcked = 0; //reset
	  tiCwnd++; // trigger changes for trace to pick up
	  spCurrBuffData->spDest->eCcApplied = TRUE;

	  /* Cancel any pending RTT measurement on this
	   * destination. Stephan Baucke (2004-04-27) suggested this
	   * action as a fix for the following simple scenario:
	   *
	   * - Host A sends packets 1, 2 and 3 to host B, and choses 3 for
	   *   an RTT measurement
	   *
	   * - Host B receives all packets correctly and sends ACK1, ACK2,
	   *   and ACK3.
	   *
	   * - ACK2 and ACK3 are lost on the return path
	   *
	   * - Eventually a timeout fires for packet 2, and A retransmits 2
	   *
	   * - Upon receipt of 2, B sends a cumulative ACK3 (since it has
	   *   received 2 & 3 before)
	   *
	   * - Since packet 3 has never been retransmitted, the SCTP code
	   *   actually accepts the ACK for an RTT measurement, although it
	   *   was sent in reply to the retransmission of 2, which results
	   *   in a much too high RTT estimate. Since this case tends to
	   *   happen in case of longer link interruptions, the error is
	   *   often amplified by subsequent timer backoffs.
	   */
	  spCurrBuffData->spDest->eRtoPending = FALSE; 

	  /****** Begin CMT Change *******/
	  /* Set the recover variable to avoid multiple cwnd cuts for losses
	   * in the same window (ie, round-trip).
	   */
	  spCurrBuffData->spDest->uiRecover = 
	    GetHighestOutstandingTsn(spCurrBuffData->spDest);
	  /****** End CMT Change *******/
	}

      /****** Begin CMT Change *******/
      /* To specify which destinationto apply LIMIT_ONE_PACKET to. 
       * Earlier, every destination got one packet rtx out when 
       * rtxmarkedchunks was called with LIMIT_ONE_PACKET.
       */
      if(spCurrBuffData->eMarkedForRtx == FAST_RTX)
      {
	spCurrBuffData->spDest->eRtxLimit = RTX_LIMIT_ONE_PACKET;
      }
      /****** End CMT Change *******/
    }

  /****** Begin CMT Change *******/
  eMarkedChunksPending = AnyMarkedChunks();
  /****** End CMT Change *******/

  /* possible that no chunks are pending retransmission since they could be 
   * advanced ack'd 
   */
  if(eMarkedChunksPending == TRUE)
    RtxMarkedChunks(RTX_LIMIT_ONE_PACKET);

  DBG_X(FastRtx);
}