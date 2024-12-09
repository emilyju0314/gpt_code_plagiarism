int MMGraphRunner::debug_fused_op(torch::jit::Stack& stack) {
  auto debug_type = get_debug_type();
  if (debug_type == DebugType::NONE) {
    return -1;
  }
  torch::jit::Stack copyStack;
  std::string debug_tag;
  if (debug_type == DebugType::CPU) {
    debug_tag = "cpu";
    for (auto &ival : stack) {
      if (ival.isTensor()) {
        auto cpu_tensor = ival.deepcopy().toTensor().to("cpu");
        copyStack.push_back(cpu_tensor);
      } else if (ival.isModule()) {
        auto cpu_module = ival.deepcopy().toModule();
        cpu_module.to(at::kCPU);
        copyStack.push_back(cpu_module._ivalue());
      } else {
        CNLOG(DBG) << "stack has non tensor/module ival";
        copyStack.push_back(ival);
      }
    }
  } else if (debug_type == DebugType::CNNL) {
    debug_tag = "catch_cnnl";
    for (auto &ival : stack) {
      if (ival.isTensor()) {
        copyStack.push_back(ival.deepcopy());
      } else {
        CNLOG(DBG) << "stack has non tensor ival";
        copyStack.push_back(ival.deepcopy());
      }
    }
  }
  runFallback(copyStack);
  // record the current number of the fused kernel;
  static int id = 0;
  int idx_out = 0;
  for (auto o : copyStack) {
    if (!o.isTensor()) {
      continue;
    }
    std::string file = debug_tag + "_jitouttensor_MLUFusionGroup" +
                       std::to_string(id)+"_" + std::to_string(idx_out);
    utils::saveTensor(o.toTensor().to("cpu"), file);
    ++idx_out;
  }
  return id++;
}