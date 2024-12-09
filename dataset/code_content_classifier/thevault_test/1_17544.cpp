std::vector<int> postprocess(proteus::InferenceResponseOutput& output, int k) {
  auto* data = static_cast<std::vector<float>*>(output.getData());
  auto size = output.getSize();

  std::vector<double> softmax;
  softmax.resize(size);

  calc_softmax(data->data(), size, softmax.data());
  return get_top_k(softmax.data(), size, k);
}