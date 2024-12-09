TEST_F(SegmentGraphTest, testFusionAliasing1) {
  const auto graph_string = R"IR(
    graph(%0 : Tensor,
          %1 : Tensor):
      %12 : int = prim::Constant[value=1]()
      %2.1 : Tensor = aten::mul(%0, %1)
      %2 : Tensor = aten::mul(%2.1, %1)
      %3 : Tensor = aten::add_(%2, %1, %12)
      %4 : Tensor = aten::mul(%2, %1)
      %5 : Tensor = aten::add(%2, %4, %12)
      return (%5))IR";
  auto g = std::make_shared<torch::jit::Graph>();
  torch::jit::parseIR(graph_string, g.get());
  g->lint();

  jit::partition::Partitioner partitioner(is_supported_1);
  partitioner.fuseNodesForMM(g);
  torch::jit::EliminateDeadCode(g);

  torch::jit::testing::FileCheck()
      .check("torch_mlu::MLUFusionGroup_0")
      ->check("return")
      ->check_not("torch_mlu::MLUFusionGroup_1")
      ->run(*g);
}