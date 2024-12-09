TEST(ResolvingGraphTest, UnusedInitializerIsIgnored) {
  ASSERT_TRUE(kSchemasRegistered);

  Model model("UnusedInitializerIsIgnored");
  auto& graph = model.MainGraph();

  std::vector<NodeArg*> inputs;
  std::vector<NodeArg*> outputs;

  TypeProto tensor_int32;
  tensor_int32.mutable_tensor_type()->set_elem_type(TensorProto_DataType_INT32);
  tensor_int32.mutable_tensor_type()->mutable_shape()->add_dim()->set_dim_value(1);

  auto& input_arg_a = graph.GetOrCreateNodeArg("node_a_in_1", &tensor_int32);
  auto& output_arg_a = graph.GetOrCreateNodeArg("node_a_out_1", &tensor_int32);

  inputs.push_back(&input_arg_a);
  outputs.push_back(&output_arg_a);
  graph.AddNode("a", "Identity_Fake", "a", inputs, outputs);

  TensorProto initializer_tensor;
  initializer_tensor.set_name("unused");
  initializer_tensor.add_dims(1);
  initializer_tensor.add_float_data(1.f);
  initializer_tensor.set_data_type(onnx::TensorProto_DataType_FLOAT);

  graph.AddInitializedTensor(initializer_tensor);
  ASSERT_TRUE(graph.GetAllInitializedTensors().size() == 1);

  auto status = graph.Resolve();
  ASSERT_TRUE(status.IsOK()) << status.ErrorMessage();
  ASSERT_TRUE(graph.GetAllInitializedTensors().empty());

  // serialize and reload so we check the loaded from proto path in SetGraphInputsOutputs
  auto proto = model.ToProto();
  std::stringstream s1;
  model.ToProto().SerializeToOstream(&s1);

  ModelProto model_proto;
  const bool result = model_proto.ParseFromIstream(&s1);
  ASSERT_TRUE(result) << "Failed to load model from serialized protobuf";

  std::shared_ptr<onnxruntime::Model> p_tmp_model;
  auto x = onnxruntime::Model::Load(model_proto, p_tmp_model, nullptr);

  auto& graph2 = p_tmp_model->MainGraph();
  status = graph2.Resolve();
  EXPECT_TRUE(status.IsOK()) << status.ErrorMessage();
  ASSERT_TRUE(graph.GetAllInitializedTensors().empty());
}