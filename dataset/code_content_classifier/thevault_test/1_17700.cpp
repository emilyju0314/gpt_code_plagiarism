TEST(Scan, UnknownDimInSubgraphOutput) {
  Model model("ScanBody");
  auto& graph = model.MainGraph();

  TypeProto float_tensor;
  float_tensor.mutable_tensor_type()->set_elem_type(TensorProto_DataType_FLOAT);
  float_tensor.mutable_tensor_type()->mutable_shape()->add_dim()->set_dim_param("param");
  TypeProto int_tensor;
  int_tensor.mutable_tensor_type()->set_elem_type(TensorProto_DataType_INT64);
  int_tensor.mutable_tensor_type()->mutable_shape()->add_dim()->set_dim_param("param");

  auto& state_in_1 = graph.GetOrCreateNodeArg("state_in_1", &float_tensor);
  auto& scan_in_1 = graph.GetOrCreateNodeArg("scan_in_1", &float_tensor);

  auto& state_out_1 = graph.GetOrCreateNodeArg("state_out_1", &float_tensor);
  auto& scan_out_1 = graph.GetOrCreateNodeArg("scan_out_1", &float_tensor);

  graph.AddNode("node1", "Identity", "Copy state_in_1 to scan_out_1", {&state_in_1}, {&scan_out_1});
  graph.AddNode("node2", "Identity", "Copy scan_in_1 to state_out_1", {&scan_in_1}, {&state_out_1});

  graph.SetInputOrder({&state_in_1, &scan_in_1});
  graph.SetOutputOrder({&state_out_1, &scan_out_1});

  auto status = graph.Resolve();
  EXPECT_EQ(status, Status::OK());

  auto& scan_body = graph.ToGraphProto();

  // Construct and run scan test
  ScanOpTester test;

  int64_t batch_size = 1, sequence_len = 3, input_size = 1;
  std::vector<int64_t> seq_shape{batch_size, sequence_len, input_size};
  std::vector<int64_t> state_shape{batch_size, input_size};

  test.AddAttribute("body", scan_body);
  test.AddAttribute<int64_t>("num_scan_inputs", 1);
  test.AddMissingOptionalInput<int64_t>();

  // we add a symbolic dimension to both the initial state and the scan input so we test
  // the path that handles loop state variables (OutputIterator::Initialize) and
  // the path that handles subgraph outputs (OutputIterator::MakeConcrete).
  // Note that we cross the values over in the subgraph, so the symbolic dimension in
  // initial_state_1 affects scan_out_1, and the symbolic dimension in scan_input_1 affects state_out_1.
  test.AddShapeToTensorData(true, 1);  // add shape and symbolic dim in dim 1 for initial_state_1
  test.AddInput<float>("initial_state_1", state_shape, {0.0});
  test.AddShapeToTensorData(true, 2);  // add shape and symbolic dim in dim 2 for scan_input_1
  test.AddInput<float>("scan_input_1", seq_shape, {1.0, 2.0, 3.0});

  test.AddOutput<float>("final_state_1", state_shape, {3.0});
  test.AddOutput<float>("scan_output_1", seq_shape, {0.0, 1.0, 2.0});

  test.Run();
}