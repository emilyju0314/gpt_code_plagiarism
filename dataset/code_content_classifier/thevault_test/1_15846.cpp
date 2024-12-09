int
NSFilGuide::pathDistance(string* psTarget, string* psSource, bool bWithSemantic, DBITBLNAME sensCle)
{
	// Trivial cases
	//
	if (!psSource || !psTarget)
    return pathDistanceInfinite;

  if (*psSource == *psTarget)
    return pathDistanceExact;

  if ((*psSource == string("")) || (*psTarget == string("")))
    return pathDistanceInfinite;

  // More complex cases
  //

  bool bJokerInTarget = false;

  // Not to waste time : if no joker and no semantics, leave now
  //
  if ((psTarget->find(string("*")) != string::npos) ||
      (psTarget->find(string("?")) != string::npos))
    bJokerInTarget = true;

  if (!bWithSemantic && !bJokerInTarget)
    return pathDistanceInfinite;

  // Target parsing
  //
  VecteurString VectItemTarget;
  DecomposeChaine(psTarget, &VectItemTarget);
  // Should never occur; just by security
  if (VectItemTarget.empty())
    return pathDistanceInfinite;

  // Source semantic parsing
  //
  VecteurString VectItemSource;
  DecomposeChaine(psSource, &VectItemSource);
  // Should never occur; just by security
  if (VectItemSource.empty())
    return pathDistanceInfinite;

  VecteurItem SourceVecEquivalentItem;

  // First, if there are jokers in the target, we try a pure generic approach
  // in order not to waste time in the semantic network
  //
  if (bJokerInTarget)
  {
  	// Building the vector with only the generic concepts of source path elements
  	for (EquiItemIter iterSource = VectItemSource.begin(); iterSource != VectItemSource.end(); iterSource++)
  	{
        VecteurString* pEquivalentItem = new VecteurString();

      pEquivalentItem->push_back(new string(*(*iterSource)));
      pEquivalentItem->push_back(new ItemGenerique );
      pEquivalentItem->push_back(new SousChemin );
      pEquivalentItem->push_back(new SousCheminNonVide );

        sort(pEquivalentItem->begin(), pEquivalentItem->end(), inferieure);
        SourceVecEquivalentItem.push_back(pEquivalentItem);
  	}

    int iPureGenericDistance = specificPathDistance(&VectItemTarget, &SourceVecEquivalentItem, &VectItemSource);
    if (iPureGenericDistance < pathDistanceInfinite)
        return pathDistanceGeneric + iPureGenericDistance;

    SourceVecEquivalentItem.vider();
  }

  if (!bWithSemantic)
    return pathDistanceInfinite;

  // Building the vector with all the semantic related concepts of source path elements
  //
  for (EquiItemIter iterSource = VectItemSource.begin(); iterSource != VectItemSource.end(); iterSource++)
  {
    VecteurString* pEquivalentItem = new VecteurString();

    chercheEquivalent(*(*iterSource), pEquivalentItem, string("ES"), sensCle);
    sort(pEquivalentItem->begin(), pEquivalentItem->end(), inferieure);

    SourceVecEquivalentItem.push_back(pEquivalentItem);
  }

  // If can we find jokers in the target, it means generic + semantic
  //
  if (bJokerInTarget)
  {
        int iGenericSemantic = specificPathDistance(&VectItemTarget, &SourceVecEquivalentItem, &VectItemSource);
    if (iGenericSemantic < pathDistanceInfinite)
        return pathDistanceSemanticGeneric + iGenericSemantic;
    else
        return pathDistanceInfinite;
  }

  int iPureSemantic = specificPathDistance(&VectItemTarget, &SourceVecEquivalentItem, &VectItemSource);
  if (iPureSemantic < pathDistanceInfinite)
    return pathDistanceSemantic + iPureSemantic;
  else
    return pathDistanceInfinite;
}