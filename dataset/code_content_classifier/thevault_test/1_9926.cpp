void StackTransformMetadata::sanitizeVregs(MachineLiveValPtr &LV,
                                           const MachineInstr *SM) const {
  typedef MachineGeneratedVal::ValueGenInst::OpType OpType;
  typedef MachineGeneratedVal::RegInstructionBase RegInstruction;

  if(!LV) return;
  if(LV->isGenerated()) {
    MachineGeneratedVal *MGV = (MachineGeneratedVal *)LV.get();
    MachineGeneratedVal::ValueGenInstList &Inst = MGV->getInstructions();
    for(size_t i = 0, num = Inst.size(); i < num; i++) {
      if(Inst[i]->opType() == OpType::Register) {
        RegInstruction *RI = (RegInstruction *)Inst[i].get();
        if(!TRI->isVirtualRegister(RI->getReg())) {
          if(RI->getReg() == TRI->getFrameRegister(*MF)) continue;
          // TODO walk through stackmap and see if physical register in
          // instruction is contained in stackmap
          LV.reset(nullptr);
          return;
        }
        else if(!SMVregs.at(SM).count(RI->getReg())) {
          DEBUG(dbgs() << "WARNING: vreg "
                       << TargetRegisterInfo::virtReg2Index(RI->getReg())
                       << " used to generate value not handled in stackmap\n");
          LV.reset(nullptr);
          return;
        }
        else {
          assert(VRM->hasPhys(RI->getReg()) && "Invalid virtual register");
          RI->setReg(VRM->getPhys(RI->getReg()));
        }
      }
    }
  }
}