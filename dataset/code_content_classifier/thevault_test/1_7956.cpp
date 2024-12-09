bool IsUnconditionalJump(const insn_t& instruction) {
  if (is_indirect_jump_insn(instruction) && GetArchitecture() == kX86) {
    return true;
  }
  if (GetArchitecture() == kMips &&
      (instruction.itype == MIPS_b || instruction.itype == MIPS_bal ||
       instruction.itype == MIPS_jalr || instruction.itype == MIPS_j ||
       instruction.itype == MIPS_jr || instruction.itype == MIPS_jal ||
       instruction.itype == MIPS_jalx)) {
    return true;
  }

  size_t count = 0;
  xrefblk_t referencesOut;
  for (bool ok = referencesOut.first_from(instruction.ea, XREF_ALL); ok;
       ok = referencesOut.next_from(), ++count) {
    if (referencesOut.iscode && referencesOut.type != fl_JF &&
        referencesOut.type != fl_JN) {
      // we have a code reference that is neither jump short nor jump far
      return false;
    }
  }
  return count == 1;
}