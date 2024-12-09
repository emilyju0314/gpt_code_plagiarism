ModRefInfo BasicAAResult::getModRefInfo(const CallBase *Call,
                                        const MemoryLocation &Loc,
                                        AAQueryInfo &AAQI) {
  assert(notDifferentParent(Call, Loc.Ptr) &&
         "AliasAnalysis query involving multiple functions!");

  const Value *Object = getUnderlyingObject(Loc.Ptr);

  // Calls marked 'tail' cannot read or write allocas from the current frame
  // because the current frame might be destroyed by the time they run. However,
  // a tail call may use an alloca with byval. Calling with byval copies the
  // contents of the alloca into argument registers or stack slots, so there is
  // no lifetime issue.
  if (isa<AllocaInst>(Object))
    if (const CallInst *CI = dyn_cast<CallInst>(Call))
      if (CI->isTailCall() &&
          !CI->getAttributes().hasAttrSomewhere(Attribute::ByVal))
        return ModRefInfo::NoModRef;

  // Stack restore is able to modify unescaped dynamic allocas. Assume it may
  // modify them even though the alloca is not escaped.
  if (auto *AI = dyn_cast<AllocaInst>(Object))
    if (!AI->isStaticAlloca() && isIntrinsicCall(Call, Intrinsic::stackrestore))
      return ModRefInfo::Mod;

  // If the pointer is to a locally allocated object that does not escape,
  // then the call can not mod/ref the pointer unless the call takes the pointer
  // as an argument, and itself doesn't capture it.
  if (!isa<Constant>(Object) && Call != Object &&
      isNonEscapingLocalObject(Object, &AAQI.IsCapturedCache)) {

    // Optimistically assume that call doesn't touch Object and check this
    // assumption in the following loop.
    ModRefInfo Result = ModRefInfo::NoModRef;
    bool IsMustAlias = true;

    unsigned OperandNo = 0;
    for (auto CI = Call->data_operands_begin(), CE = Call->data_operands_end();
         CI != CE; ++CI, ++OperandNo) {
      // Only look at the no-capture or byval pointer arguments.  If this
      // pointer were passed to arguments that were neither of these, then it
      // couldn't be no-capture.
      if (!(*CI)->getType()->isPointerTy() ||
          (!Call->doesNotCapture(OperandNo) &&
           OperandNo < Call->getNumArgOperands() &&
           !Call->isByValArgument(OperandNo)))
        continue;

      // Call doesn't access memory through this operand, so we don't care
      // if it aliases with Object.
      if (Call->doesNotAccessMemory(OperandNo))
        continue;

      // If this is a no-capture pointer argument, see if we can tell that it
      // is impossible to alias the pointer we're checking.
      AliasResult AR = getBestAAResults().alias(
          MemoryLocation::getBeforeOrAfter(*CI),
          MemoryLocation::getBeforeOrAfter(Object), AAQI);
      if (AR != MustAlias)
        IsMustAlias = false;
      // Operand doesn't alias 'Object', continue looking for other aliases
      if (AR == NoAlias)
        continue;
      // Operand aliases 'Object', but call doesn't modify it. Strengthen
      // initial assumption and keep looking in case if there are more aliases.
      if (Call->onlyReadsMemory(OperandNo)) {
        Result = setRef(Result);
        continue;
      }
      // Operand aliases 'Object' but call only writes into it.
      if (Call->doesNotReadMemory(OperandNo)) {
        Result = setMod(Result);
        continue;
      }
      // This operand aliases 'Object' and call reads and writes into it.
      // Setting ModRef will not yield an early return below, MustAlias is not
      // used further.
      Result = ModRefInfo::ModRef;
      break;
    }

    // No operand aliases, reset Must bit. Add below if at least one aliases
    // and all aliases found are MustAlias.
    if (isNoModRef(Result))
      IsMustAlias = false;

    // Early return if we improved mod ref information
    if (!isModAndRefSet(Result)) {
      if (isNoModRef(Result))
        return ModRefInfo::NoModRef;
      return IsMustAlias ? setMust(Result) : clearMust(Result);
    }
  }

  // If the call is malloc/calloc like, we can assume that it doesn't
  // modify any IR visible value.  This is only valid because we assume these
  // routines do not read values visible in the IR.  TODO: Consider special
  // casing realloc and strdup routines which access only their arguments as
  // well.  Or alternatively, replace all of this with inaccessiblememonly once
  // that's implemented fully.
  if (isMallocOrCallocLikeFn(Call, &TLI)) {
    // Be conservative if the accessed pointer may alias the allocation -
    // fallback to the generic handling below.
    if (getBestAAResults().alias(MemoryLocation::getBeforeOrAfter(Call),
                                 Loc, AAQI) == NoAlias)
      return ModRefInfo::NoModRef;
  }

  // The semantics of memcpy intrinsics either exactly overlap or do not
  // overlap, i.e., source and destination of any given memcpy are either
  // no-alias or must-alias.
  if (auto *Inst = dyn_cast<AnyMemCpyInst>(Call)) {
    AliasResult SrcAA =
        getBestAAResults().alias(MemoryLocation::getForSource(Inst), Loc, AAQI);
    AliasResult DestAA =
        getBestAAResults().alias(MemoryLocation::getForDest(Inst), Loc, AAQI);
    // It's also possible for Loc to alias both src and dest, or neither.
    ModRefInfo rv = ModRefInfo::NoModRef;
    if (SrcAA != NoAlias)
      rv = setRef(rv);
    if (DestAA != NoAlias)
      rv = setMod(rv);
    return rv;
  }

  // While the assume intrinsic is marked as arbitrarily writing so that
  // proper control dependencies will be maintained, it never aliases any
  // particular memory location.
  if (isIntrinsicCall(Call, Intrinsic::assume))
    return ModRefInfo::NoModRef;

  // Like assumes, guard intrinsics are also marked as arbitrarily writing so
  // that proper control dependencies are maintained but they never mods any
  // particular memory location.
  //
  // *Unlike* assumes, guard intrinsics are modeled as reading memory since the
  // heap state at the point the guard is issued needs to be consistent in case
  // the guard invokes the "deopt" continuation.
  if (isIntrinsicCall(Call, Intrinsic::experimental_guard))
    return ModRefInfo::Ref;
  // The same applies to deoptimize which is essentially a guard(false).
  if (isIntrinsicCall(Call, Intrinsic::experimental_deoptimize))
    return ModRefInfo::Ref;

  // Like assumes, invariant.start intrinsics were also marked as arbitrarily
  // writing so that proper control dependencies are maintained but they never
  // mod any particular memory location visible to the IR.
  // *Unlike* assumes (which are now modeled as NoModRef), invariant.start
  // intrinsic is now modeled as reading memory. This prevents hoisting the
  // invariant.start intrinsic over stores. Consider:
  // *ptr = 40;
  // *ptr = 50;
  // invariant_start(ptr)
  // int val = *ptr;
  // print(val);
  //
  // This cannot be transformed to:
  //
  // *ptr = 40;
  // invariant_start(ptr)
  // *ptr = 50;
  // int val = *ptr;
  // print(val);
  //
  // The transformation will cause the second store to be ignored (based on
  // rules of invariant.start)  and print 40, while the first program always
  // prints 50.
  if (isIntrinsicCall(Call, Intrinsic::invariant_start))
    return ModRefInfo::Ref;

  // The AAResultBase base class has some smarts, lets use them.
  return AAResultBase::getModRefInfo(Call, Loc, AAQI);
}