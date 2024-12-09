AliasResult BasicAAResult::aliasCheck(const Value *V1, LocationSize V1Size,
                                      const AAMDNodes &V1AAInfo,
                                      const Value *V2, LocationSize V2Size,
                                      const AAMDNodes &V2AAInfo,
                                      AAQueryInfo &AAQI, const Value *O1,
                                      const Value *O2) {
  // If either of the memory references is empty, it doesn't matter what the
  // pointer values are.
  if (V1Size.isZero() || V2Size.isZero())
    return NoAlias;

  // Strip off any casts if they exist.
  V1 = V1->stripPointerCastsAndInvariantGroups();
  V2 = V2->stripPointerCastsAndInvariantGroups();

  // If V1 or V2 is undef, the result is NoAlias because we can always pick a
  // value for undef that aliases nothing in the program.
  if (isa<UndefValue>(V1) || isa<UndefValue>(V2))
    return NoAlias;

  // Are we checking for alias of the same value?
  // Because we look 'through' phi nodes, we could look at "Value" pointers from
  // different iterations. We must therefore make sure that this is not the
  // case. The function isValueEqualInPotentialCycles ensures that this cannot
  // happen by looking at the visited phi nodes and making sure they cannot
  // reach the value.
  if (isValueEqualInPotentialCycles(V1, V2))
    return MustAlias;

  if (!V1->getType()->isPointerTy() || !V2->getType()->isPointerTy())
    return NoAlias; // Scalars cannot alias each other

  // Figure out what objects these things are pointing to if we can.
  if (O1 == nullptr)
    O1 = getUnderlyingObject(V1, MaxLookupSearchDepth);

  if (O2 == nullptr)
    O2 = getUnderlyingObject(V2, MaxLookupSearchDepth);

  // Null values in the default address space don't point to any object, so they
  // don't alias any other pointer.
  if (const ConstantPointerNull *CPN = dyn_cast<ConstantPointerNull>(O1))
    if (!NullPointerIsDefined(&F, CPN->getType()->getAddressSpace()))
      return NoAlias;
  if (const ConstantPointerNull *CPN = dyn_cast<ConstantPointerNull>(O2))
    if (!NullPointerIsDefined(&F, CPN->getType()->getAddressSpace()))
      return NoAlias;

  if (O1 != O2) {
    // If V1/V2 point to two different objects, we know that we have no alias.
    if (isIdentifiedObject(O1) && isIdentifiedObject(O2))
      return NoAlias;

    // Constant pointers can't alias with non-const isIdentifiedObject objects.
    if ((isa<Constant>(O1) && isIdentifiedObject(O2) && !isa<Constant>(O2)) ||
        (isa<Constant>(O2) && isIdentifiedObject(O1) && !isa<Constant>(O1)))
      return NoAlias;

    // Function arguments can't alias with things that are known to be
    // unambigously identified at the function level.
    if ((isa<Argument>(O1) && isIdentifiedFunctionLocal(O2)) ||
        (isa<Argument>(O2) && isIdentifiedFunctionLocal(O1)))
      return NoAlias;

    // If one pointer is the result of a call/invoke or load and the other is a
    // non-escaping local object within the same function, then we know the
    // object couldn't escape to a point where the call could return it.
    //
    // Note that if the pointers are in different functions, there are a
    // variety of complications. A call with a nocapture argument may still
    // temporary store the nocapture argument's value in a temporary memory
    // location if that memory location doesn't escape. Or it may pass a
    // nocapture value to other functions as long as they don't capture it.
    if (isEscapeSource(O1) &&
        isNonEscapingLocalObject(O2, &AAQI.IsCapturedCache))
      return NoAlias;
    if (isEscapeSource(O2) &&
        isNonEscapingLocalObject(O1, &AAQI.IsCapturedCache))
      return NoAlias;
  }

  // If the size of one access is larger than the entire object on the other
  // side, then we know such behavior is undefined and can assume no alias.
  bool NullIsValidLocation = NullPointerIsDefined(&F);
  if ((isObjectSmallerThan(
          O2, getMinimalExtentFrom(*V1, V1Size, DL, NullIsValidLocation), DL,
          TLI, NullIsValidLocation)) ||
      (isObjectSmallerThan(
          O1, getMinimalExtentFrom(*V2, V2Size, DL, NullIsValidLocation), DL,
          TLI, NullIsValidLocation)))
    return NoAlias;

  // If one the accesses may be before the accessed pointer, canonicalize this
  // by using unknown after-pointer sizes for both accesses. This is
  // equivalent, because regardless of which pointer is lower, one of them
  // will always came after the other, as long as the underlying objects aren't
  // disjoint. We do this so that the rest of BasicAA does not have to deal
  // with accesses before the base pointer, and to improve cache utilization by
  // merging equivalent states.
  if (V1Size.mayBeBeforePointer() || V2Size.mayBeBeforePointer()) {
    V1Size = LocationSize::afterPointer();
    V2Size = LocationSize::afterPointer();
  }

  // Check the cache before climbing up use-def chains. This also terminates
  // otherwise infinitely recursive queries.
  AAQueryInfo::LocPair Locs(MemoryLocation(V1, V1Size, V1AAInfo),
                            MemoryLocation(V2, V2Size, V2AAInfo));
  if (V1 > V2)
    std::swap(Locs.first, Locs.second);
  const auto &Pair = AAQI.AliasCache.try_emplace(
      Locs, AAQueryInfo::CacheEntry{NoAlias, 0});
  if (!Pair.second) {
    auto &Entry = Pair.first->second;
    if (!Entry.isDefinitive()) {
      // Remember that we used an assumption.
      ++Entry.NumAssumptionUses;
      ++NumAssumptionUses;
    }
    return Entry.Result;
  }

  int OrigNumAssumptionUses = NumAssumptionUses;
  unsigned OrigNumAssumptionBasedResults = AssumptionBasedResults.size();
  AliasResult Result = aliasCheckRecursive(V1, V1Size, V1AAInfo, V2, V2Size,
                                           V2AAInfo, AAQI, O1, O2);

  auto It = AAQI.AliasCache.find(Locs);
  assert(It != AAQI.AliasCache.end() && "Must be in cache");
  auto &Entry = It->second;

  // Check whether a NoAlias assumption has been used, but disproven.
  bool AssumptionDisproven = Entry.NumAssumptionUses > 0 && Result != NoAlias;
  if (AssumptionDisproven)
    Result = MayAlias;

  // This is a definitive result now, when considered as a root query.
  NumAssumptionUses -= Entry.NumAssumptionUses;
  Entry.Result = Result;
  Entry.NumAssumptionUses = -1;

  // If the assumption has been disproven, remove any results that may have
  // been based on this assumption. Do this after the Entry updates above to
  // avoid iterator invalidation.
  if (AssumptionDisproven)
    while (AssumptionBasedResults.size() > OrigNumAssumptionBasedResults)
      AAQI.AliasCache.erase(AssumptionBasedResults.pop_back_val());

  // The result may still be based on assumptions higher up in the chain.
  // Remember it, so it can be purged from the cache later.
  if (OrigNumAssumptionUses != NumAssumptionUses && Result != MayAlias)
    AssumptionBasedResults.push_back(Locs);
  return Result;
}