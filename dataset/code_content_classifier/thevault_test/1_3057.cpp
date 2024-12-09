bool RISCVDAGToDAGISel::MatchSROIW(SDNode *N) const {
  assert(N->getOpcode() == ISD::OR);
  assert(N->getOperand(0).getOpcode() == ISD::SRL);
  assert(isa<ConstantSDNode>(N->getOperand(1)));
  assert(isa<ConstantSDNode>(N->getOperand(0).getOperand(1)));

  // The IsRV64 predicate is checked after PatFrag predicates so we can get
  // here even on RV32.
  if (!Subtarget->is64Bit())
    return false;

  SDValue Srl = N->getOperand(0);
  uint64_t VC1 = N->getConstantOperandVal(1);
  uint64_t VC2 = Srl.getConstantOperandVal(1);

  // Immediate range should be enforced by uimm5 predicate.
  assert(VC2 < 32 && "Unexpected immediate");
  return VC1 == maskTrailingZeros<uint64_t>(32 - VC2);
}