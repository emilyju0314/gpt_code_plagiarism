void SILWalaInstructionVisitor::perInstruction() {
  Wala.print(Wala.makePosition(
      InstrInfo->startLine, InstrInfo->startCol,
      InstrInfo->endLine, InstrInfo->endCol)
  );

  if (Print) {
    llvm::outs() << "\t [INSTR] #" << InstrInfo->num;
    llvm::outs() << ", [OPNUM] " << InstrInfo->id << "\n";
    llvm::outs() << "\t --> File: " << InstrInfo->Filename << "\n";

    // Has no location information
    if (InstrInfo->srcType == -1) {
      llvm::outs() << "\t **** No source information. \n";

      // Has only start information
    } else {
      llvm::outs() << "\t ++++ Start - Line " << InstrInfo->startLine << ":"
                   << InstrInfo->startCol << "\n";
    }

    // Has end information
    if (InstrInfo->srcType == 0) {
      llvm::outs() << "\t ---- End - Line " << InstrInfo->endLine;
      llvm::outs() << ":" << InstrInfo->endCol << "\n";
    }

    // Memory Behavior
    switch (InstrInfo->memBehavior) {
    case SILInstruction::MemoryBehavior::None: {
      break;
    }
    case SILInstruction::MemoryBehavior::MayRead: {
      llvm::outs() << "\t\t +++ [MEM-R]: May read from memory. \n";
      break;
    }
    case SILInstruction::MemoryBehavior::MayWrite: {
      llvm::outs() << "\t\t +++ [MEM-W]: May write to memory. \n";
      break;
    }
    case SILInstruction::MemoryBehavior::MayReadWrite: {
      llvm::outs() << "\t\t +++ [MEM-RW]: May read or write memory. \n";
      break;
    }
    case SILInstruction::MemoryBehavior::MayHaveSideEffects: {
      llvm::outs() << "\t\t +++ [MEM-F]: May have side effects. \n";
    }
    }

    // Releasing Behavior
    switch (InstrInfo->relBehavior) {
    case SILInstruction::ReleasingBehavior::DoesNotRelease: {
      llvm::outs() << "\t\t [REL]: Does not release memory. \n";
      break;
    }
    case SILInstruction::ReleasingBehavior::MayRelease: {
      llvm::outs() << "\t\t [REL]: May release memory. \n";
      break;
    }
    }

    // Show operands, if they exist
    for (auto op = InstrInfo->ops.begin(); op != InstrInfo->ops.end(); ++op) {
      llvm::outs() << "\t\t [OPER]: " << *op;
    }

    llvm::outs() << "\n";
  }
}