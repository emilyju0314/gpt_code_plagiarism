bool
TermsParser::FindFlexClinicalTerm(NSThesaurusInfo *pClinicalBase, string* pLexiqueCode)
{
  if ((NULL == pClinicalBase) || (NULL == pLexiqueCode) || (string("") == *pLexiqueCode))
    return false;

  VectString aFlexLabels;

  // First step: get all flex labels for a given lexique code
  //
  NSEpiFlechiesDB Flechies(pContexte);
  bool bSuccess = Flechies.getAllLabelsForCode(*pLexiqueCode, &aFlexLabels);

  if ((false == bSuccess) && (true == aFlexLabels.empty()))
    return false;

  if (true == aFlexLabels.empty())
    return false;

  // Second step: check if one of these labels exists in 3BT
  //
  for (IterString it = aFlexLabels.begin(); aFlexLabels.end() != it; it++)
    if (true == FindClinicalTerm(pClinicalBase, *it))
      return true;

  return false;
}