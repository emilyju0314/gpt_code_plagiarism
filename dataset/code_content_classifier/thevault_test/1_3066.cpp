FunctionModRefBehavior BasicAAResult::getModRefBehavior(const CallBase *Call) {
  if (Call->doesNotAccessMemory())
    // Can't do better than this.
    return FMRB_DoesNotAccessMemory;

  FunctionModRefBehavior Min = FMRB_UnknownModRefBehavior;

  // If the callsite knows it only reads memory, don't return worse
  // than that.
  if (Call->onlyReadsMemory())
    Min = FMRB_OnlyReadsMemory;
  else if (Call->doesNotReadMemory())
    Min = FMRB_OnlyWritesMemory;

  if (Call->onlyAccessesArgMemory())
    Min = FunctionModRefBehavior(Min & FMRB_OnlyAccessesArgumentPointees);
  else if (Call->onlyAccessesInaccessibleMemory())
    Min = FunctionModRefBehavior(Min & FMRB_OnlyAccessesInaccessibleMem);
  else if (Call->onlyAccessesInaccessibleMemOrArgMem())
    Min = FunctionModRefBehavior(Min & FMRB_OnlyAccessesInaccessibleOrArgMem);

  // If the call has operand bundles then aliasing attributes from the function
  // it calls do not directly apply to the call.  This can be made more precise
  // in the future.
  if (!Call->hasOperandBundles())
    if (const Function *F = Call->getCalledFunction())
      Min =
          FunctionModRefBehavior(Min & getBestAAResults().getModRefBehavior(F));

  return Min;
}