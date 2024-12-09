static void encodeDoRebase(Rebase &rebase, raw_svector_ostream &os) {
  assert(rebase.consecutiveCount != 0);
  if (rebase.consecutiveCount <= REBASE_IMMEDIATE_MASK) {
    os << static_cast<uint8_t>(REBASE_OPCODE_DO_REBASE_IMM_TIMES |
                               rebase.consecutiveCount);
  } else {
    os << static_cast<uint8_t>(REBASE_OPCODE_DO_REBASE_ULEB_TIMES);
    encodeULEB128(rebase.consecutiveCount, os);
  }
  rebase.consecutiveCount = 0;
}