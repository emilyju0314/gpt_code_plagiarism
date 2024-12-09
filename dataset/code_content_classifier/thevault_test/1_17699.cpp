TEST(Scan, MixedTypeInputs) {
  // Construct scan body subgraph with 2 state variables, 2 scan inputs, 2 scan outputs
  // of different types (1 float and 1 int64 of each):
  // state-in-1 => scan-out-1
  // scan-in-1 => state-out-1
  // state-in-2 => scan-out-2
  // scan-in-2 => state-out-2

  Model model("ScanBody");
  auto& graph = model.MainGraph();

  TypeProto float_tensor;
  float_tensor.mutable_tensor_type()->set_elem_type(TensorProto_DataType_FLOAT);
  float_tensor.mutable_tensor_type()->mutable_shape()->add_dim()->set_dim_value(1);
  TypeProto int_tensor;
  int_tensor.mutable_tensor_type()->set_elem_type(TensorProto_DataType_INT64);
  int_tensor.mutable_tensor_type()->mutable_shape()->add_dim()->set_dim_value(1);

  auto& state_in_1 = graph.GetOrCreateNodeArg("state_in_1", &float_tensor);
  auto& state_in_2 = graph.GetOrCreateNodeArg("state_in_2", &int_tensor);
  auto& scan_in_1 = graph.GetOrCreateNodeArg("scan_in_1", &float_tensor);
  auto& scan_in_2 = graph.GetOrCreateNodeArg("scan_in_2", &int_tensor);

  auto& state_out_1 = graph.GetOrCreateNodeArg("state_out_1", &float_tensor);
  auto& state_out_2 = graph.GetOrCreateNodeArg("state_out_2", &int_tensor);
  auto& scan_out_1 = graph.GetOrCreateNodeArg("scan_out_1", &float_tensor);
  auto& scan_out_2 = graph.GetOrCreateNodeArg("scan_out_2", &int_tensor);

  graph.AddNode("node1", "Identity", "Copy state_in_1 to scan_out_1", {&state_in_1}, {&scan_out_1});
  graph.AddNode("node2", "Identity", "Copy state_in_2 to scan_out_2", {&state_in_2}, {&scan_out_2});
  graph.AddNode("node3", "Identity", "Copy scan_in_1 to state_out_1", {&scan_in_1}, {&state_out_1});
  graph.AddNode("node4", "Identity", "Copy scan_in_2 to state_out_2", {&scan_in_2}, {&state_out_2});

  graph.SetInputOrder({&state_in_1, &state_in_2, &scan_in_1, &scan_in_2});
  graph.SetOutputOrder({&state_out_1, &state_out_2, &scan_out_1, &scan_out_2});

  auto status = graph.Resolve();
  EXPECT_EQ(status, Status::OK());

  auto& scan_body = graph.ToGraphProto();

  // Construct and run scan test
  ScanOpTester test;

  int64_t batch_size = 1, sequence_len = 3, input_size = 1;
  std::vector<int64_t> seq_shape{batch_size, sequence_len, input_size};
  std::vector<int64_t> state_shape{batch_size, input_size};

  test.AddAttribute("body", scan_body);
  test.AddAttribute<int64_t>("num_scan_inputs", 2);

  test.AddMissingOptionalInput<int64_t>();
  test.AddInput<float>("initial_state_1", state_shape, {0.0});
  test.AddInput<int64_t>("initial_state_2", state_shape, {0});
  test.AddInput<float>("scan_input_1", seq_shape, {1.0, 2.0, 3.0});
  test.AddInput<int64_t>("scan_input_2", seq_shape, {1, 2, 3});

  test.AddOutput<float>("final_state_1", state_shape, {3.0});
  test.AddOutput<int64_t>("final_state_2", state_shape, {3});
  test.AddOutput<float>("scan_output_1", seq_shape, {0.0, 1.0, 2.0});
  test.AddOutput<int64_t>("scan_output_2", seq_shape, {0, 1, 2});

  test.Run();
}