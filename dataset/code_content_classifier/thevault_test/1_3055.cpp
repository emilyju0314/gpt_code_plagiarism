bool RISCVDAGToDAGISel::MatchSLOI(SDNode *N) const {
  assert(N->getOpcode() == ISD::OR);
  assert(N->getOperand(0).getOpcode() == ISD::SHL);
  assert(isa<ConstantSDNode>(N->getOperand(1)));
  assert(isa<ConstantSDNode>(N->getOperand(0).getOperand(1)));

  SDValue Shl = N->getOperand(0);
  if (Subtarget->is64Bit()) {
    uint64_t VC1 = N->getConstantOperandVal(1);
    uint64_t VC2 = Shl.getConstantOperandVal(1);
    return VC1 == maskTrailingOnes<uint64_t>(VC2);
  }

  uint32_t VC1 = N->getConstantOperandVal(1);
  uint32_t VC2 = Shl.getConstantOperandVal(1);
  return VC1 == maskTrailingOnes<uint32_t>(VC2);
}