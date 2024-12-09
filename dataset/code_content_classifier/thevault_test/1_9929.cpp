void StackTransformMetadata::warnUnhandled() const {
  std::string Msg;
  const CallInst *IRCall;
  const Function *CalledFunc;

  for(auto S = SM.begin(), SE = SM.end(); S != SE; S++)
  {
    const MachineInstr *MISM = getMISM(*S);
    const MachineInstr *MICall = getMICall(*S);
    const RegValsMap &CurVregs = SMVregs.at(MISM);
    const StackValsMap &CurSS = SMStackSlots.at(MISM);
    IRCall = findCalledFunc(getIRSM(*S));
    CalledFunc = IRCall->getCalledFunction();
    assert(IRCall && "No call instruction for stackmap");

    // Search for virtual registers not handled by the stackmap
    for(unsigned i = 0; i < MRI->getNumVirtRegs(); i++) {
      unsigned Vreg = TargetRegisterInfo::index2VirtReg(i);

      // Virtual register allocated to physical register
      if(VRM->hasPhys(Vreg) && isVregLiveAcrossInstr(Vreg, MICall) &&
         CurVregs.find(Vreg) == CurVregs.end()) {
        Msg = "Stack transformation: unhandled register ";
        Msg += TRI->getName(VRM->getPhys(Vreg));
        displayWarning(Msg, IRCall, CalledFunc);
      }
    }

    // Search for all stack slots not handled by the stackmap
    for(int SS = MFI->getObjectIndexBegin(), e = MFI->getObjectIndexEnd();
        SS < e; SS++) {
      if(!MFI->isDeadObjectIndex(SS) &&
         isSSLiveAcrossInstr(SS, MICall) && CurSS.find(SS) == CurSS.end()) {
        Msg = "Stack transformation: unhandled stack slot ";
        Msg += std::to_string(SS);
        displayWarning(Msg, IRCall, CalledFunc);
      }
    }
  }
}