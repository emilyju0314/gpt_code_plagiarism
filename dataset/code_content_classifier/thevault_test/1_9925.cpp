void StackTransformMetadata::dumpStackSlot(int SS, const Value *IRVal) const {
  assert(!MFI->isDeadObjectIndex(SS) && "Invalid stack slot");
  IRVal->printAsOperand(dbgs());
  dbgs() << ": in stack slot " << SS << " (size: " << MFI->getObjectSize(SS)
         << ")\n";
}