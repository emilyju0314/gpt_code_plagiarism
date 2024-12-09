bool BasicAAResult::pointsToConstantMemory(const MemoryLocation &Loc,
                                           AAQueryInfo &AAQI, bool OrLocal) {
  assert(Visited.empty() && "Visited must be cleared after use!");

  unsigned MaxLookup = 8;
  SmallVector<const Value *, 16> Worklist;
  Worklist.push_back(Loc.Ptr);
  do {
    const Value *V = getUnderlyingObject(Worklist.pop_back_val());
    if (!Visited.insert(V).second) {
      Visited.clear();
      return AAResultBase::pointsToConstantMemory(Loc, AAQI, OrLocal);
    }

    // An alloca instruction defines local memory.
    if (OrLocal && isa<AllocaInst>(V))
      continue;

    // A global constant counts as local memory for our purposes.
    if (const GlobalVariable *GV = dyn_cast<GlobalVariable>(V)) {
      // Note: this doesn't require GV to be "ODR" because it isn't legal for a
      // global to be marked constant in some modules and non-constant in
      // others.  GV may even be a declaration, not a definition.
      if (!GV->isConstant()) {
        Visited.clear();
        return AAResultBase::pointsToConstantMemory(Loc, AAQI, OrLocal);
      }
      continue;
    }

    // If both select values point to local memory, then so does the select.
    if (const SelectInst *SI = dyn_cast<SelectInst>(V)) {
      Worklist.push_back(SI->getTrueValue());
      Worklist.push_back(SI->getFalseValue());
      continue;
    }

    // If all values incoming to a phi node point to local memory, then so does
    // the phi.
    if (const PHINode *PN = dyn_cast<PHINode>(V)) {
      // Don't bother inspecting phi nodes with many operands.
      if (PN->getNumIncomingValues() > MaxLookup) {
        Visited.clear();
        return AAResultBase::pointsToConstantMemory(Loc, AAQI, OrLocal);
      }
      for (Value *IncValue : PN->incoming_values())
        Worklist.push_back(IncValue);
      continue;
    }

    // Otherwise be conservative.
    Visited.clear();
    return AAResultBase::pointsToConstantMemory(Loc, AAQI, OrLocal);
  } while (!Worklist.empty() && --MaxLookup);

  Visited.clear();
  return Worklist.empty();
}