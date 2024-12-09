void TFNetwork::Forward(bool debug, const NetworkIO &input, const TransposedArray *input_transpose,
                        NetworkScratch *scratch, NetworkIO *output) {
  std::vector<std::pair<std::string, Tensor>> tf_inputs;
  int depth = input_shape_.depth();
  ASSERT_HOST(depth == input.NumFeatures());
  // TODO(rays) Allow batching. For now batch_size = 1.
  const StrideMap &stride_map = input.stride_map();
  // TF requires a tensor of shape float[batch, height, width, depth].
  TensorShape shape{1, stride_map.Size(FD_HEIGHT), stride_map.Size(FD_WIDTH), depth};
  Tensor input_tensor(tensorflow::DT_FLOAT, shape);
  // The flat() member gives a 1d array, with a data() member to get the data.
  auto eigen_tensor = input_tensor.flat<float>();
  memcpy(eigen_tensor.data(), input.f(0), input.Width() * depth * sizeof(input.f(0)[0]));
  // Add the tensor to the vector of inputs.
  tf_inputs.emplace_back(model_proto_.image_input(), input_tensor);

  // Provide tensors giving the width and/or height of the image if they are
  // required. Some tf ops require a separate tensor with knowledge of the
  // size of the input as they cannot obtain it from the input tensor. This is
  // usually true in the case of ops that process a batch of variable-sized
  // objects.
  if (!model_proto_.image_widths().empty()) {
    TensorShape size_shape{1};
    Tensor width_tensor(tensorflow::DT_INT64, size_shape);
    auto eigen_wtensor = width_tensor.flat<tensorflow::int64>();
    *eigen_wtensor.data() = stride_map.Size(FD_WIDTH);
    tf_inputs.emplace_back(model_proto_.image_widths(), width_tensor);
  }
  if (!model_proto_.image_heights().empty()) {
    TensorShape size_shape{1};
    Tensor height_tensor(tensorflow::DT_INT64, size_shape);
    auto eigen_htensor = height_tensor.flat<tensorflow::int64>();
    *eigen_htensor.data() = stride_map.Size(FD_HEIGHT);
    tf_inputs.emplace_back(model_proto_.image_heights(), height_tensor);
  }
  std::vector<std::string> target_layers = {model_proto_.output_layer()};
  std::vector<Tensor> outputs;
  Status s = session_->Run(tf_inputs, target_layers, {}, &outputs);
  if (!s.ok())
    tprintf("session->Run failed:%s\n", s.error_message().c_str());
  ASSERT_HOST(s.ok());
  ASSERT_HOST(outputs.size() == 1);
  const Tensor &output_tensor = outputs[0];
  // Check the dimensions of the output.
  ASSERT_HOST(output_tensor.shape().dims() == 3);
  int output_batch = output_tensor.shape().dim_size(0);
  int output_steps = output_tensor.shape().dim_size(1);
  int output_depth = output_tensor.shape().dim_size(2);
  ASSERT_HOST(output_batch == 1);
  ASSERT_HOST(output_depth == output_shape_.depth());
  output->Resize2d(false, output_steps, output_depth);
  auto eigen_output = output_tensor.flat<float>();
  memcpy(output->f(0), eigen_output.data(), output_steps * output_depth * sizeof(output->f(0)[0]));
}