static bool isWriteOnlyParam(const CallBase *Call, unsigned ArgIdx,
                             const TargetLibraryInfo &TLI) {
  if (Call->paramHasAttr(ArgIdx, Attribute::WriteOnly))
    return true;

  // We can bound the aliasing properties of memset_pattern16 just as we can
  // for memcpy/memset.  This is particularly important because the
  // LoopIdiomRecognizer likes to turn loops into calls to memset_pattern16
  // whenever possible.
  // FIXME Consider handling this in InferFunctionAttr.cpp together with other
  // attributes.
  LibFunc F;
  if (Call->getCalledFunction() &&
      TLI.getLibFunc(*Call->getCalledFunction(), F) &&
      F == LibFunc_memset_pattern16 && TLI.has(F))
    if (ArgIdx == 0)
      return true;

  // TODO: memset_pattern4, memset_pattern8
  // TODO: _chk variants
  // TODO: strcmp, strcpy

  return false;
}