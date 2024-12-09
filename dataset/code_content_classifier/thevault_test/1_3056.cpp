bool RISCVDAGToDAGISel::MatchSROI(SDNode *N) const {
  assert(N->getOpcode() == ISD::OR);
  assert(N->getOperand(0).getOpcode() == ISD::SRL);
  assert(isa<ConstantSDNode>(N->getOperand(1)));
  assert(isa<ConstantSDNode>(N->getOperand(0).getOperand(1)));

  SDValue Srl = N->getOperand(0);
  if (Subtarget->is64Bit()) {
    uint64_t VC1 = N->getConstantOperandVal(1);
    uint64_t VC2 = Srl.getConstantOperandVal(1);
    return VC1 == maskLeadingOnes<uint64_t>(VC2);
  }

  uint32_t VC1 = N->getConstantOperandVal(1);
  uint32_t VC2 = Srl.getConstantOperandVal(1);
  return VC1 == maskLeadingOnes<uint32_t>(VC2);
}