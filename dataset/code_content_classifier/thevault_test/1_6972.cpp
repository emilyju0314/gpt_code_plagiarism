int SctpAgent::SetLossrate(int iNsAddr, float fLossrate)
{

  Node_S *spCurrNode = NULL;
  SctpDest_S *spCurrDest = NULL;

  for(spCurrNode = sDestList.spHead;
      spCurrNode != NULL;
      spCurrNode = spCurrNode->spNext)
    {
      spCurrDest = (SctpDest_S *) spCurrNode->vpData;
      if(spCurrDest->iNsAddr == iNsAddr)
	{
	  spCurrDest->fLossrate = fLossrate;
	  return (TCL_OK);
	}
    }
  return (TCL_ERROR);
}