const Value *BasicAAResult::GetLinearExpression(
    const Value *V, APInt &Scale, APInt &Offset, unsigned &ZExtBits,
    unsigned &SExtBits, const DataLayout &DL, unsigned Depth,
    AssumptionCache *AC, DominatorTree *DT, bool &NSW, bool &NUW) {
  assert(V->getType()->isIntegerTy() && "Not an integer value");

  // Limit our recursion depth.
  if (Depth == 6) {
    Scale = 1;
    Offset = 0;
    return V;
  }

  if (const ConstantInt *Const = dyn_cast<ConstantInt>(V)) {
    // If it's a constant, just convert it to an offset and remove the variable.
    // If we've been called recursively, the Offset bit width will be greater
    // than the constant's (the Offset's always as wide as the outermost call),
    // so we'll zext here and process any extension in the isa<SExtInst> &
    // isa<ZExtInst> cases below.
    Offset += Const->getValue().zextOrSelf(Offset.getBitWidth());
    assert(Scale == 0 && "Constant values don't have a scale");
    return V;
  }

  if (const BinaryOperator *BOp = dyn_cast<BinaryOperator>(V)) {
    if (ConstantInt *RHSC = dyn_cast<ConstantInt>(BOp->getOperand(1))) {
      // If we've been called recursively, then Offset and Scale will be wider
      // than the BOp operands. We'll always zext it here as we'll process sign
      // extensions below (see the isa<SExtInst> / isa<ZExtInst> cases).
      APInt RHS = RHSC->getValue().zextOrSelf(Offset.getBitWidth());

      switch (BOp->getOpcode()) {
      default:
        // We don't understand this instruction, so we can't decompose it any
        // further.
        Scale = 1;
        Offset = 0;
        return V;
      case Instruction::Or:
        // X|C == X+C if all the bits in C are unset in X.  Otherwise we can't
        // analyze it.
        if (!MaskedValueIsZero(BOp->getOperand(0), RHSC->getValue(), DL, 0, AC,
                               BOp, DT)) {
          Scale = 1;
          Offset = 0;
          return V;
        }
        LLVM_FALLTHROUGH;
      case Instruction::Add:
        V = GetLinearExpression(BOp->getOperand(0), Scale, Offset, ZExtBits,
                                SExtBits, DL, Depth + 1, AC, DT, NSW, NUW);
        Offset += RHS;
        break;
      case Instruction::Sub:
        V = GetLinearExpression(BOp->getOperand(0), Scale, Offset, ZExtBits,
                                SExtBits, DL, Depth + 1, AC, DT, NSW, NUW);
        Offset -= RHS;
        break;
      case Instruction::Mul:
        V = GetLinearExpression(BOp->getOperand(0), Scale, Offset, ZExtBits,
                                SExtBits, DL, Depth + 1, AC, DT, NSW, NUW);
        Offset *= RHS;
        Scale *= RHS;
        break;
      case Instruction::Shl:
        V = GetLinearExpression(BOp->getOperand(0), Scale, Offset, ZExtBits,
                                SExtBits, DL, Depth + 1, AC, DT, NSW, NUW);

        // We're trying to linearize an expression of the kind:
        //   shl i8 -128, 36
        // where the shift count exceeds the bitwidth of the type.
        // We can't decompose this further (the expression would return
        // a poison value).
        if (Offset.getBitWidth() < RHS.getLimitedValue() ||
            Scale.getBitWidth() < RHS.getLimitedValue()) {
          Scale = 1;
          Offset = 0;
          return V;
        }

        Offset <<= RHS.getLimitedValue();
        Scale <<= RHS.getLimitedValue();
        // the semantics of nsw and nuw for left shifts don't match those of
        // multiplications, so we won't propagate them.
        NSW = NUW = false;
        return V;
      }

      if (isa<OverflowingBinaryOperator>(BOp)) {
        NUW &= BOp->hasNoUnsignedWrap();
        NSW &= BOp->hasNoSignedWrap();
      }
      return V;
    }
  }

  // Since GEP indices are sign extended anyway, we don't care about the high
  // bits of a sign or zero extended value - just scales and offsets.  The
  // extensions have to be consistent though.
  if (isa<SExtInst>(V) || isa<ZExtInst>(V)) {
    Value *CastOp = cast<CastInst>(V)->getOperand(0);
    unsigned NewWidth = V->getType()->getPrimitiveSizeInBits();
    unsigned SmallWidth = CastOp->getType()->getPrimitiveSizeInBits();
    unsigned OldZExtBits = ZExtBits, OldSExtBits = SExtBits;
    const Value *Result =
        GetLinearExpression(CastOp, Scale, Offset, ZExtBits, SExtBits, DL,
                            Depth + 1, AC, DT, NSW, NUW);

    // zext(zext(%x)) == zext(%x), and similarly for sext; we'll handle this
    // by just incrementing the number of bits we've extended by.
    unsigned ExtendedBy = NewWidth - SmallWidth;

    if (isa<SExtInst>(V) && ZExtBits == 0) {
      // sext(sext(%x, a), b) == sext(%x, a + b)

      if (NSW) {
        // We haven't sign-wrapped, so it's valid to decompose sext(%x + c)
        // into sext(%x) + sext(c). We'll sext the Offset ourselves:
        unsigned OldWidth = Offset.getBitWidth();
        Offset = Offset.trunc(SmallWidth).sext(NewWidth).zextOrSelf(OldWidth);
      } else {
        // We may have signed-wrapped, so don't decompose sext(%x + c) into
        // sext(%x) + sext(c)
        Scale = 1;
        Offset = 0;
        Result = CastOp;
        ZExtBits = OldZExtBits;
        SExtBits = OldSExtBits;
      }
      SExtBits += ExtendedBy;
    } else {
      // sext(zext(%x, a), b) = zext(zext(%x, a), b) = zext(%x, a + b)

      if (!NUW) {
        // We may have unsigned-wrapped, so don't decompose zext(%x + c) into
        // zext(%x) + zext(c)
        Scale = 1;
        Offset = 0;
        Result = CastOp;
        ZExtBits = OldZExtBits;
        SExtBits = OldSExtBits;
      }
      ZExtBits += ExtendedBy;
    }

    return Result;
  }

  Scale = 1;
  Offset = 0;
  return V;
}