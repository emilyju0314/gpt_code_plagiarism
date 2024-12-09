static void pushWriteback(SILGenFunction &SGF,
                          SILLocation loc,
                          std::unique_ptr<LogicalPathComponent> &&comp,
                          ManagedValue base,
                          MaterializedLValue materialized) {
  assert(SGF.InWritebackScope);

  // Push a cleanup to execute the writeback consistently.
  auto &context = SGF.FormalEvalContext;
  LValueWritebackCleanup &cleanup =
      SGF.Cleanups.pushCleanup<LValueWritebackCleanup>();
  CleanupHandle handle = SGF.Cleanups.getTopCleanup();

  context.push<ExclusiveBorrowFormalAccess>(loc, std::move(comp), base,
                                            materialized, handle);
  cleanup.Depth = context.stable_begin();
}