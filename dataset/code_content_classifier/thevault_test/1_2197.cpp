bool SameFileLine(const llvm::DWARFDebugLine::Row& reference,
                  const llvm::DWARFDebugLine::Row& candidate, bool greedy) {
  if (greedy && candidate.Line == 0)
    return true;
  return reference.File == candidate.File && reference.Line == candidate.Line;
}