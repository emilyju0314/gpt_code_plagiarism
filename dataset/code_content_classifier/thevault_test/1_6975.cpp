void SctpAgent::InsertDuplicateTsn(u_int uiTsn)
{
  DBG_I(InsertDuplicateTsn);
  Node_S *spCurrNode = NULL;
  Node_S *spPrevNode = NULL;
  Node_S *spNewNode = NULL;
  u_int uiCurrTsn;

  /* linear search
   */
  for(spPrevNode = NULL, spCurrNode = sDupTsnList.spHead; 
      spCurrNode != NULL;
      spPrevNode = spCurrNode, spCurrNode = spCurrNode->spNext)
    {
      uiCurrTsn = ((SctpDupTsn_S *) spCurrNode->vpData)->uiTsn;
      if(uiTsn <= uiCurrTsn)
	break;
    }

  /* If we reached the end of the list 
   * OR we found the location in the list where it should go (assuming it 
   * isn't already there)... insert it.
   */
  if( (spCurrNode == NULL) || (uiTsn != uiCurrTsn) )
    {
      spNewNode = new Node_S;
      spNewNode->eType = NODE_TYPE_DUP_TSN;
      spNewNode->vpData = new SctpDupTsn_S;
      ((SctpDupTsn_S *) spNewNode->vpData)->uiTsn = uiTsn;
      InsertNode(&sDupTsnList, spPrevNode, spNewNode, spCurrNode);
    }

  DBG_X(InsertDuplicateTsn);
}