BasicAAResult::DecomposedGEP
BasicAAResult::DecomposeGEPExpression(const Value *V, const DataLayout &DL,
                                      AssumptionCache *AC, DominatorTree *DT) {
  // Limit recursion depth to limit compile time in crazy cases.
  unsigned MaxLookup = MaxLookupSearchDepth;
  SearchTimes++;
  const Instruction *CxtI = dyn_cast<Instruction>(V);

  unsigned MaxPointerSize = getMaxPointerSize(DL);
  DecomposedGEP Decomposed;
  Decomposed.Offset = APInt(MaxPointerSize, 0);
  Decomposed.HasCompileTimeConstantScale = true;
  do {
    // See if this is a bitcast or GEP.
    const Operator *Op = dyn_cast<Operator>(V);
    if (!Op) {
      // The only non-operator case we can handle are GlobalAliases.
      if (const GlobalAlias *GA = dyn_cast<GlobalAlias>(V)) {
        if (!GA->isInterposable()) {
          V = GA->getAliasee();
          continue;
        }
      }
      Decomposed.Base = V;
      return Decomposed;
    }

    if (Op->getOpcode() == Instruction::BitCast ||
        Op->getOpcode() == Instruction::AddrSpaceCast) {
      V = Op->getOperand(0);
      continue;
    }

    const GEPOperator *GEPOp = dyn_cast<GEPOperator>(Op);
    if (!GEPOp) {
      if (const auto *PHI = dyn_cast<PHINode>(V)) {
        // Look through single-arg phi nodes created by LCSSA.
        if (PHI->getNumIncomingValues() == 1) {
          V = PHI->getIncomingValue(0);
          continue;
        }
      } else if (const auto *Call = dyn_cast<CallBase>(V)) {
        // CaptureTracking can know about special capturing properties of some
        // intrinsics like launder.invariant.group, that can't be expressed with
        // the attributes, but have properties like returning aliasing pointer.
        // Because some analysis may assume that nocaptured pointer is not
        // returned from some special intrinsic (because function would have to
        // be marked with returns attribute), it is crucial to use this function
        // because it should be in sync with CaptureTracking. Not using it may
        // cause weird miscompilations where 2 aliasing pointers are assumed to
        // noalias.
        if (auto *RP = getArgumentAliasingToReturnedPointer(Call, false)) {
          V = RP;
          continue;
        }
      }

      Decomposed.Base = V;
      return Decomposed;
    }

    // Don't attempt to analyze GEPs over unsized objects.
    if (!GEPOp->getSourceElementType()->isSized()) {
      Decomposed.Base = V;
      return Decomposed;
    }

    // Don't attempt to analyze GEPs if index scale is not a compile-time
    // constant.
    if (isa<ScalableVectorType>(GEPOp->getSourceElementType())) {
      Decomposed.Base = V;
      Decomposed.HasCompileTimeConstantScale = false;
      return Decomposed;
    }

    unsigned AS = GEPOp->getPointerAddressSpace();
    // Walk the indices of the GEP, accumulating them into BaseOff/VarIndices.
    gep_type_iterator GTI = gep_type_begin(GEPOp);
    unsigned PointerSize = DL.getPointerSizeInBits(AS);
    // Assume all GEP operands are constants until proven otherwise.
    bool GepHasConstantOffset = true;
    for (User::const_op_iterator I = GEPOp->op_begin() + 1, E = GEPOp->op_end();
         I != E; ++I, ++GTI) {
      const Value *Index = *I;
      // Compute the (potentially symbolic) offset in bytes for this index.
      if (StructType *STy = GTI.getStructTypeOrNull()) {
        // For a struct, add the member offset.
        unsigned FieldNo = cast<ConstantInt>(Index)->getZExtValue();
        if (FieldNo == 0)
          continue;

        Decomposed.Offset += DL.getStructLayout(STy)->getElementOffset(FieldNo);
        continue;
      }

      // For an array/pointer, add the element offset, explicitly scaled.
      if (const ConstantInt *CIdx = dyn_cast<ConstantInt>(Index)) {
        if (CIdx->isZero())
          continue;
        Decomposed.Offset +=
            DL.getTypeAllocSize(GTI.getIndexedType()).getFixedSize() *
            CIdx->getValue().sextOrTrunc(MaxPointerSize);
        continue;
      }

      GepHasConstantOffset = false;

      APInt Scale(MaxPointerSize,
                  DL.getTypeAllocSize(GTI.getIndexedType()).getFixedSize());
      unsigned ZExtBits = 0, SExtBits = 0;

      // If the integer type is smaller than the pointer size, it is implicitly
      // sign extended to pointer size.
      unsigned Width = Index->getType()->getIntegerBitWidth();
      if (PointerSize > Width)
        SExtBits += PointerSize - Width;

      // Use GetLinearExpression to decompose the index into a C1*V+C2 form.
      APInt IndexScale(Width, 0), IndexOffset(Width, 0);
      bool NSW = true, NUW = true;
      const Value *OrigIndex = Index;
      Index = GetLinearExpression(Index, IndexScale, IndexOffset, ZExtBits,
                                  SExtBits, DL, 0, AC, DT, NSW, NUW);

      // The GEP index scale ("Scale") scales C1*V+C2, yielding (C1*V+C2)*Scale.
      // This gives us an aggregate computation of (C1*Scale)*V + C2*Scale.

      // It can be the case that, even through C1*V+C2 does not overflow for
      // relevant values of V, (C2*Scale) can overflow. In that case, we cannot
      // decompose the expression in this way.
      //
      // FIXME: C1*Scale and the other operations in the decomposed
      // (C1*Scale)*V+C2*Scale can also overflow. We should check for this
      // possibility.
      bool Overflow;
      APInt ScaledOffset = IndexOffset.sextOrTrunc(MaxPointerSize)
                           .smul_ov(Scale, Overflow);
      if (Overflow) {
        Index = OrigIndex;
        IndexScale = 1;
        IndexOffset = 0;

        ZExtBits = SExtBits = 0;
        if (PointerSize > Width)
          SExtBits += PointerSize - Width;
      } else {
        Decomposed.Offset += ScaledOffset;
        Scale *= IndexScale.sextOrTrunc(MaxPointerSize);
      }

      // If we already had an occurrence of this index variable, merge this
      // scale into it.  For example, we want to handle:
      //   A[x][x] -> x*16 + x*4 -> x*20
      // This also ensures that 'x' only appears in the index list once.
      for (unsigned i = 0, e = Decomposed.VarIndices.size(); i != e; ++i) {
        if (Decomposed.VarIndices[i].V == Index &&
            Decomposed.VarIndices[i].ZExtBits == ZExtBits &&
            Decomposed.VarIndices[i].SExtBits == SExtBits) {
          Scale += Decomposed.VarIndices[i].Scale;
          Decomposed.VarIndices.erase(Decomposed.VarIndices.begin() + i);
          break;
        }
      }

      // Make sure that we have a scale that makes sense for this target's
      // pointer size.
      Scale = adjustToPointerSize(Scale, PointerSize);

      if (!!Scale) {
        VariableGEPIndex Entry = {Index, ZExtBits, SExtBits, Scale, CxtI};
        Decomposed.VarIndices.push_back(Entry);
      }
    }

    // Take care of wrap-arounds
    if (GepHasConstantOffset)
      Decomposed.Offset = adjustToPointerSize(Decomposed.Offset, PointerSize);

    // Analyze the base pointer next.
    V = GEPOp->getOperand(0);
  } while (--MaxLookup);

  // If the chain of expressions is too deep, just return early.
  Decomposed.Base = V;
  SearchLimitReached++;
  return Decomposed;
}