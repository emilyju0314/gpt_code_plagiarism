static void handleUnreachable(Block* block, bool breakabilityKnown=false, bool hasBreak=false) {
  if (block->type == unreachable) return; // nothing to do
  if (block->list.size() == 0) return; // nothing to do
  // if we are concrete, stop - even an unreachable child
  // won't change that (since we have a break with a value,
  // or the final child flows out a value)
  if (isConcreteType(block->type)) return;
  // look for an unreachable child
  for (auto* child : block->list) {
    if (child->type == unreachable) {
      // there is an unreachable child, so we are unreachable, unless we have a break
      if (!breakabilityKnown) {
        hasBreak = BranchUtils::BranchSeeker::hasNamed(block, block->name);
      }
      if (!hasBreak) {
        block->type = unreachable;
      }
      return;
    }
  }
}