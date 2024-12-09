bool StreamAnalyzer::IsDirectRun(Instruction& cur_instr,
                                 const Instruction& next_instr) {
  return (cur_instr.dev_ctx_ == next_instr.dev_ctx_ ||
          interpretercore::IsMemcpyD2H(cur_instr) ||
          interpretercore::IsMemcpyH2D(next_instr));
}