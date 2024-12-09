FunctionModRefBehavior BasicAAResult::getModRefBehavior(const Function *F) {
  // If the function declares it doesn't access memory, we can't do better.
  if (F->doesNotAccessMemory())
    return FMRB_DoesNotAccessMemory;

  FunctionModRefBehavior Min = FMRB_UnknownModRefBehavior;

  // If the function declares it only reads memory, go with that.
  if (F->onlyReadsMemory())
    Min = FMRB_OnlyReadsMemory;
  else if (F->doesNotReadMemory())
    Min = FMRB_OnlyWritesMemory;

  if (F->onlyAccessesArgMemory())
    Min = FunctionModRefBehavior(Min & FMRB_OnlyAccessesArgumentPointees);
  else if (F->onlyAccessesInaccessibleMemory())
    Min = FunctionModRefBehavior(Min & FMRB_OnlyAccessesInaccessibleMem);
  else if (F->onlyAccessesInaccessibleMemOrArgMem())
    Min = FunctionModRefBehavior(Min & FMRB_OnlyAccessesInaccessibleOrArgMem);

  return Min;
}