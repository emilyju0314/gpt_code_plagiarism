const ::ONNX_NAMESPACE::TypeProto* FindTypeBinding(const onnxruntime::Node& node, const std::string& name) {
  const ONNX_NAMESPACE::OpSchema& op_schema = *node.Op();
  // search inputs:
  const size_t len = node.InputArgCount().size();
  ORT_ENFORCE(len <= op_schema.inputs().size());
  int actual_index = 0;
  for (size_t formal_index = 0; formal_index != len; ++formal_index) {
    auto& param = op_schema.inputs()[formal_index];
    if ((param.GetTypeStr() == name) || (param.GetName() == name)) {
      // return type of any corresponding actual parameter, if present
      for (int i = 0, end = node.InputArgCount()[formal_index]; i < end; ++i) {
        const onnxruntime::NodeArg* arg = node.InputDefs()[actual_index + i];
        if (!arg->Exists()) continue;  // a missing optional argument
        return arg->TypeAsProto();
      }
    }
    actual_index += node.InputArgCount()[formal_index];
  }
  // search outputs:
  auto& actual_outputs = node.OutputDefs();
  auto num_actual_outputs = actual_outputs.size();
  auto last_formal = op_schema.outputs().size() - 1;
  for (size_t i = 0; i != num_actual_outputs; ++i) {
    const onnxruntime::NodeArg* arg = actual_outputs[i];
    if (!arg->Exists()) continue;
    auto& formal = op_schema.outputs()[std::min(i, last_formal)];
    const auto& formal_typestr = formal.GetTypeStr();  // for easier debugging
    const auto& formal_name = formal.GetName();        // for easier debugging
    if ((formal_typestr == name) || (formal_name == name)) {
      return arg->TypeAsProto();
    }
  }
  return nullptr;
}