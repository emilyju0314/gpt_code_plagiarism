void SctpAgent::UpdateCumAck()
{
  DBG_I(UpdateCumAck);
  Node_S *spCurrNode = NULL;

  if(sRecvTsnBlockList.uiLength == 0)
    {
      DBG_X(UpdateCumAck);
      return;
    }

  for(spCurrNode = sRecvTsnBlockList.spHead; 
      spCurrNode != NULL; 
      spCurrNode = spCurrNode->spNext)
    {
      if( uiCumAck+1 == ((SctpRecvTsnBlock_S *)spCurrNode->vpData)->uiStartTsn)
	{
	  uiCumAck = ((SctpRecvTsnBlock_S *)spCurrNode->vpData)->uiEndTsn;
	}
      else
        {
          DBG_X(UpdateCumAck);
          return;
        }
    }

  DBG_X(UpdateCumAck);
}