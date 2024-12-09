MachineLiveValPtr
StackTransformMetadata::getTargetValue(const MachineInstr *MI,
                                       const MachineInstr *SM) const {
  if(!MI) return MachineLiveValPtr(nullptr);

  // Immediates can be handled in an architecture-agnostic way
  if(MI->isMoveImmediate()) {
    unsigned Size = 8;
    uint64_t Value = UINT64_MAX;
    for(unsigned i = 0, e = MI->getNumOperands(); i < e; i++) {
      const MachineOperand &MO = MI->getOperand(i);
      if(MO.isImm()) Value = MO.getImm();
      if(MO.isFPImm()) {
        // We need to encode the bits exactly as they are to represent the
        // double, so switch types and read relevant info
        APInt Bits(MO.getFPImm()->getValueAPF().bitcastToAPInt());
        Size = Bits.getBitWidth() / 8;
        Value = Bits.getZExtValue();
      }
    }
    return MachineLiveValPtr(new MachineImmediate(Size, Value, MI));
  }
  // Otherwise, drop to architecture-specific value generator
  else {
    MachineLiveValPtr MLV = TVG->getMachineValue(MI);
    sanitizeVregs(MLV, SM);
    return MLV;
  }
}