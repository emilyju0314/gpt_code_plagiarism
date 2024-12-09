bool KernelRegistry::VerifyKernelDef(const onnxruntime::Node& node,
                                     const KernelDef& kernel_def,
                                     std::string& error_str,
                                     onnxruntime::ProviderType exec_provider) {
  // check if domain matches
  if (node.Domain() != kernel_def.Domain()) {
    std::ostringstream ostr;
    ostr << "Op: " << node.OpType()
         << " Domain mismatch: "
         << " Expected: " << kernel_def.Domain()
         << " Actual: " << node.Domain();
    error_str = ostr.str();
    return false;
  }

  // check if execution provider matches
  const auto& node_provider = node.GetExecutionProviderType();
  const auto& expected_provider = (node_provider.empty() ? exec_provider : node_provider);
  if (expected_provider != kernel_def.Provider()) {
    std::ostringstream ostr;
    ostr << "Op: " << node.OpType()
         << " Execution provider mismatch."
         << " Expected: " << expected_provider
         << " Acutal: " << kernel_def.Provider();
    error_str = ostr.str();
    return false;
  }

  // check if version matches
  int kernel_start_version, kernel_end_version;
  kernel_def.SinceVersion(&kernel_start_version, &kernel_end_version);

  int node_since_version = node.Op()->since_version();
  // Ideal case is, if schema is Since(5), current opset version is opset 7,
  // kernel_def Since(8)     Invalid
  // kernel_def Since(6)     Valid
  // kernel_def Since(5)     Valid
  // kernel_def Since(4)     Invalid
  // kernel_def Since(4, 6)  Valid

  // Right now there is no "until version" on schema, it is difficult to get opset version here.(require a lot of interface change.)
  // As a trade off, we will temporary require kernel definition to have the same since version as schema definition.
  // so kernel_def Since(6) will become invalid now.
  // After ONNX add "until version" on the schema object, we will update this place
  bool valid_version = kernel_start_version == node_since_version  // the idea case this branch should be kernel_start_version >= node_version && kernel_start_version <= until_version
                       || (kernel_start_version < node_since_version && kernel_end_version != INT_MAX && kernel_end_version >= node_since_version);
  if (!valid_version) {
    std::ostringstream ostr;
    ostr << "Op: " << node.OpType()
         << " Version mismatch."
         << " node_version: " << node_since_version
         << " kernel start version: " << kernel_start_version
         << " kernel_end_version: " << kernel_end_version;
    error_str = ostr.str();
    return false;
  }

  // check if type matches
  auto& kernel_type_constraints = kernel_def.TypeConstraints();
  for (auto& constraint : kernel_type_constraints) {
    const std::string& name = constraint.first;
    const std::vector<MLDataType>& allowed_types = constraint.second;
    const ::ONNX_NAMESPACE::TypeProto* actual_type = FindTypeBinding(node, name);

    // If actual_type is null, this represents a type-constraint on a
    // missing optional parameter, which can be skipped.
    // TODO: We should check that names specified in kernel_type_constraints are
    // valid names (of types or parameters) at the time that kernels are registered.
    if ((nullptr != actual_type) &&
        !std::any_of(allowed_types.begin(), allowed_types.end(),
                     [actual_type, &node, &error_str](const DataTypeImpl* expected_type) {
                       bool rc = expected_type->IsCompatible(*actual_type);  // for easier debugging
                       if (!rc) {
                         // TODO print type information as well
                         error_str = "Op: " + node.OpType() + " Incompatible types.";
                       }
                       return rc;
                     })) {
      return false;
    }
  }
  return true;
}