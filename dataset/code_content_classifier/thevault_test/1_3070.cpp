AliasResult
BasicAAResult::aliasSelect(const SelectInst *SI, LocationSize SISize,
                           const AAMDNodes &SIAAInfo, const Value *V2,
                           LocationSize V2Size, const AAMDNodes &V2AAInfo,
                           const Value *UnderV2, AAQueryInfo &AAQI) {
  // If the values are Selects with the same condition, we can do a more precise
  // check: just check for aliases between the values on corresponding arms.
  if (const SelectInst *SI2 = dyn_cast<SelectInst>(V2))
    if (SI->getCondition() == SI2->getCondition()) {
      AliasResult Alias =
          aliasCheck(SI->getTrueValue(), SISize, SIAAInfo, SI2->getTrueValue(),
                     V2Size, V2AAInfo, AAQI);
      if (Alias == MayAlias)
        return MayAlias;
      AliasResult ThisAlias =
          aliasCheck(SI->getFalseValue(), SISize, SIAAInfo,
                     SI2->getFalseValue(), V2Size, V2AAInfo, AAQI);
      return MergeAliasResults(ThisAlias, Alias);
    }

  // If both arms of the Select node NoAlias or MustAlias V2, then returns
  // NoAlias / MustAlias. Otherwise, returns MayAlias.
  AliasResult Alias = aliasCheck(V2, V2Size, V2AAInfo, SI->getTrueValue(),
                                 SISize, SIAAInfo, AAQI, UnderV2);
  if (Alias == MayAlias)
    return MayAlias;

  AliasResult ThisAlias = aliasCheck(V2, V2Size, V2AAInfo, SI->getFalseValue(),
                                     SISize, SIAAInfo, AAQI, UnderV2);
  return MergeAliasResults(ThisAlias, Alias);
}