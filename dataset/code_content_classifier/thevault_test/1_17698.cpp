TEST(Scan, OuterScopeAccess_NoShapeInMainGraph_TypeAndShapeInSubgraph) {
  RunOptions options{};
  options.include_dim_values_in_main_graph = false;
  options.include_types_in_subgraph = true;
  options.include_dim_values_in_subgraph = true;

  options.include_outer_scope_add = true;

  ShortSequenceOneInBatchOneLoopStateVar(options);
}