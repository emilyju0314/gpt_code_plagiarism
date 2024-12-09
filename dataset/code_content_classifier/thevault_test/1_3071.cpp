AliasResult BasicAAResult::aliasPHI(const PHINode *PN, LocationSize PNSize,
                                    const AAMDNodes &PNAAInfo, const Value *V2,
                                    LocationSize V2Size,
                                    const AAMDNodes &V2AAInfo,
                                    const Value *UnderV2, AAQueryInfo &AAQI) {
  // If the values are PHIs in the same block, we can do a more precise
  // as well as efficient check: just check for aliases between the values
  // on corresponding edges.
  if (const PHINode *PN2 = dyn_cast<PHINode>(V2))
    if (PN2->getParent() == PN->getParent()) {
      Optional<AliasResult> Alias;
      for (unsigned i = 0, e = PN->getNumIncomingValues(); i != e; ++i) {
        AliasResult ThisAlias =
            aliasCheck(PN->getIncomingValue(i), PNSize, PNAAInfo,
                       PN2->getIncomingValueForBlock(PN->getIncomingBlock(i)),
                       V2Size, V2AAInfo, AAQI);
        if (Alias)
          *Alias = MergeAliasResults(*Alias, ThisAlias);
        else
          Alias = ThisAlias;
        if (*Alias == MayAlias)
          break;
      }
      return *Alias;
    }

  SmallVector<Value *, 4> V1Srcs;
  // If a phi operand recurses back to the phi, we can still determine NoAlias
  // if we don't alias the underlying objects of the other phi operands, as we
  // know that the recursive phi needs to be based on them in some way.
  bool isRecursive = false;
  auto CheckForRecPhi = [&](Value *PV) {
    if (!EnableRecPhiAnalysis)
      return false;
    if (getUnderlyingObject(PV) == PN) {
      isRecursive = true;
      return true;
    }
    return false;
  };

  if (PV) {
    // If we have PhiValues then use it to get the underlying phi values.
    const PhiValues::ValueSet &PhiValueSet = PV->getValuesForPhi(PN);
    // If we have more phi values than the search depth then return MayAlias
    // conservatively to avoid compile time explosion. The worst possible case
    // is if both sides are PHI nodes. In which case, this is O(m x n) time
    // where 'm' and 'n' are the number of PHI sources.
    if (PhiValueSet.size() > MaxLookupSearchDepth)
      return MayAlias;
    // Add the values to V1Srcs
    for (Value *PV1 : PhiValueSet) {
      if (CheckForRecPhi(PV1))
        continue;
      V1Srcs.push_back(PV1);
    }
  } else {
    // If we don't have PhiInfo then just look at the operands of the phi itself
    // FIXME: Remove this once we can guarantee that we have PhiInfo always
    SmallPtrSet<Value *, 4> UniqueSrc;
    for (Value *PV1 : PN->incoming_values()) {
      if (isa<PHINode>(PV1))
        // If any of the source itself is a PHI, return MayAlias conservatively
        // to avoid compile time explosion. The worst possible case is if both
        // sides are PHI nodes. In which case, this is O(m x n) time where 'm'
        // and 'n' are the number of PHI sources.
        return MayAlias;

      if (CheckForRecPhi(PV1))
        continue;

      if (UniqueSrc.insert(PV1).second)
        V1Srcs.push_back(PV1);
    }
  }

  // If V1Srcs is empty then that means that the phi has no underlying non-phi
  // value. This should only be possible in blocks unreachable from the entry
  // block, but return MayAlias just in case.
  if (V1Srcs.empty())
    return MayAlias;

  // If this PHI node is recursive, indicate that the pointer may be moved
  // across iterations. We can only prove NoAlias if different underlying
  // objects are involved.
  if (isRecursive)
    PNSize = LocationSize::beforeOrAfterPointer();

  // In the recursive alias queries below, we may compare values from two
  // different loop iterations. Keep track of visited phi blocks, which will
  // be used when determining value equivalence.
  bool BlockInserted = VisitedPhiBBs.insert(PN->getParent()).second;
  auto _ = make_scope_exit([&]() {
    if (BlockInserted)
      VisitedPhiBBs.erase(PN->getParent());
  });

  // If we inserted a block into VisitedPhiBBs, alias analysis results that
  // have been cached earlier may no longer be valid. Perform recursive queries
  // with a new AAQueryInfo.
  AAQueryInfo NewAAQI;
  AAQueryInfo *UseAAQI = BlockInserted ? &NewAAQI : &AAQI;

  AliasResult Alias = aliasCheck(V2, V2Size, V2AAInfo, V1Srcs[0], PNSize,
                                 PNAAInfo, *UseAAQI, UnderV2);

  // Early exit if the check of the first PHI source against V2 is MayAlias.
  // Other results are not possible.
  if (Alias == MayAlias)
    return MayAlias;
  // With recursive phis we cannot guarantee that MustAlias/PartialAlias will
  // remain valid to all elements and needs to conservatively return MayAlias.
  if (isRecursive && Alias != NoAlias)
    return MayAlias;

  // If all sources of the PHI node NoAlias or MustAlias V2, then returns
  // NoAlias / MustAlias. Otherwise, returns MayAlias.
  for (unsigned i = 1, e = V1Srcs.size(); i != e; ++i) {
    Value *V = V1Srcs[i];

    AliasResult ThisAlias = aliasCheck(V2, V2Size, V2AAInfo, V, PNSize,
                                       PNAAInfo, *UseAAQI, UnderV2);
    Alias = MergeAliasResults(ThisAlias, Alias);
    if (Alias == MayAlias)
      break;
  }

  return Alias;
}