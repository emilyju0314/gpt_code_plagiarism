void StackTransformMetadata::dumpReg(unsigned Reg, const Value *IRVal) const {
  IRVal->printAsOperand(dbgs());
  if(TargetRegisterInfo::isPhysicalRegister(Reg))
    dbgs() << ": in register " << PrintReg(Reg, TRI);
  else {
    assert(VRM->hasPhys(Reg) && "Invalid virtual register");
    unsigned Phys = VRM->getPhys(Reg);
    dbgs() << ": in register " << PrintReg(Phys, TRI)
           << " (vreg " << TargetRegisterInfo::virtReg2Index(Reg) << ")";
  }
  dbgs() << "\n";
}