bool LowerHopToActor::processHop(HopToExecutorInst *hop) {
  auto actor = hop->getTargetExecutor();

  // Ignore hops that are already to Builtin.Executor.
  if (actor->getType().is<BuiltinExecutorType>())
    return false;

  B.setInsertionPoint(hop);

  // Get the dominating executor value for this actor, if available,
  // or else emit code to derive it.
  SILValue executor = emitGetExecutor(hop->getLoc(), actor);

  B.createHopToExecutor(hop->getLoc(), executor);

  hop->eraseFromParent();

  return true;
}