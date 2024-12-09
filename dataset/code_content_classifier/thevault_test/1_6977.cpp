void SctpAgent::UpdateRecvTsnBlocks(u_int uiTsn)
{
  DBG_I(UpdateRecvTsnBlocks);

  u_int uiLow;
  u_int uiHigh;
  u_int uiGapSize;

  Node_S *spCurrNode = NULL;
  Node_S *spPrevNode = NULL;
  Node_S *spNewNode = NULL;

  uiLow = uiCumAck + 1;

  for(spCurrNode = sRecvTsnBlockList.spHead; 
      spCurrNode != NULL; 
      spPrevNode = spCurrNode, spCurrNode = spCurrNode->spNext)
    {
      uiHigh = ((SctpRecvTsnBlock_S *)spCurrNode->vpData)->uiStartTsn - 1;
      
      /* Does uiTsn fall in the gap?
       */
      if( uiLow <= uiTsn && uiTsn <= uiHigh )
	{
	  uiGapSize = uiHigh - uiLow + 1;

	  if(uiGapSize > 1) // is the gap too big for one uiTsn to fill?
	    {
	      /* Does uiTsn border the lower edge of the current tsn block?
	       */
	      if(uiTsn == uiHigh) 
		{
		  ((SctpRecvTsnBlock_S *)spCurrNode->vpData)->uiStartTsn 
		    = uiTsn;

		  UpdateCumAck();
		  DBG_X(UpdateRecvTsnBlocks);
		  return;
		} 

	      /* Does uiTsn border the left edge of the previous tsn block?
	       */
	      else if(uiTsn == uiLow)
		{
		  if(uiTsn == uiCumAck+1) // can we increment our uiCumAck?
		    {
		      uiCumAck++;
		      UpdateCumAck();
		      DBG_X(UpdateRecvTsnBlocks);
		      return;
		    }
		  else // otherwise, move previous tsn block's right edge
		    {
		      ((SctpRecvTsnBlock_S *)spPrevNode->vpData)->uiEndTsn 
			= uiTsn;

		      UpdateCumAck();
		      DBG_X(UpdateRecvTsnBlocks);
		      return;
		    }
		}

	      /* This uiTsn creates a new tsn block in between uiLow & uiHigh
	       */
	      else 
		{   
		  spNewNode = new Node_S;
		  spNewNode->eType = NODE_TYPE_RECV_TSN_BLOCK;
		  spNewNode->vpData = new SctpRecvTsnBlock_S;
		  ((SctpRecvTsnBlock_S *)spNewNode->vpData)->uiStartTsn 
		    = uiTsn;
		  ((SctpRecvTsnBlock_S *)spNewNode->vpData)->uiEndTsn = uiTsn;

		  InsertNode(&sRecvTsnBlockList, 
			     spPrevNode, spNewNode, spCurrNode);

		  DBG_X(UpdateRecvTsnBlocks);
		  return; // no UpdateCumAck() necessary
		}
	    } 

	  else // uiGapSize == 1
	    {
	      if(uiLow == uiCumAck+1)  // can we adjust our uiCumAck?
		{
		  /* delete tsn block
		   */
		  uiCumAck 
		    = ((SctpRecvTsnBlock_S *)spCurrNode->vpData)->uiEndTsn;

		  DeleteNode(&sRecvTsnBlockList, spCurrNode);
		  spCurrNode = NULL;
		  UpdateCumAck();
		  DBG_X(UpdateRecvTsnBlocks);
		  return;
		} 
	      else  // otherwise, move previous tsn block's right edge
		{
		  ((SctpRecvTsnBlock_S *)spPrevNode->vpData)->uiEndTsn
		    = ((SctpRecvTsnBlock_S *)spCurrNode->vpData)->uiEndTsn;

		  DeleteNode(&sRecvTsnBlockList, spCurrNode);
		  spCurrNode = NULL;
		  UpdateCumAck();
		  DBG_X(UpdateRecvTsnBlocks);
		  return;
		}
	    }
	} 

      /* uiTsn is not in the gap between these two tsn blocks, so let's move 
       * our "low pointer" to one past the end of the current tsn block and 
       * continue
       */
      else 
	{         
	  uiLow =  ((SctpRecvTsnBlock_S *)spCurrNode->vpData)->uiEndTsn + 1;
	}
    }

  /* If we get here, then the list is either NULL or the end of the list has
   * been reached 
   */
  if(uiTsn == uiLow) 
    {
      if(uiTsn == uiCumAck+1) // Can we increment the uiCumAck?
	{
	  uiCumAck = uiTsn;
	  UpdateCumAck();
	  DBG_X(UpdateRecvTsnBlocks);
	  return;
        }
      
      /* Update previous tsn block by increasing it's uiEndTsn
       */
      if(spPrevNode != NULL)
	{
	  ((SctpRecvTsnBlock_S *) spPrevNode->vpData)->uiEndTsn++;	  
	}
      DBG_X(UpdateRecvTsnBlocks);
      return; // no UpdateCumAck() necessary
    } 

  /* uiTsn creates a new tsn block to go at the end of the sRecvTsnBlockList
   */
  else 
    {
      spNewNode = new Node_S;
      spNewNode->eType = NODE_TYPE_RECV_TSN_BLOCK;
      spNewNode->vpData = new SctpRecvTsnBlock_S;
      ((SctpRecvTsnBlock_S *) spNewNode->vpData)->uiStartTsn = uiTsn;
      ((SctpRecvTsnBlock_S *) spNewNode->vpData)->uiEndTsn = uiTsn;
      InsertNode(&sRecvTsnBlockList, spPrevNode, spNewNode, spCurrNode);
      DBG_X(UpdateRecvTsnBlocks);
      return; // no UpdateCumAck() necessary
    }
}