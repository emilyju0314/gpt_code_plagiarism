bool PopulateIndexExecutor::DInit() {
  PL_ASSERT(children_.size() == 1);
  PL_ASSERT(executor_context_);

  // Initialize executor state
  const planner::PopulateIndexPlan &node =
      GetPlanNode<planner::PopulateIndexPlan>();
  target_table_ = node.GetTable();
  column_ids_ = node.GetColumnIds();
  done_ = false;

  return true;
}