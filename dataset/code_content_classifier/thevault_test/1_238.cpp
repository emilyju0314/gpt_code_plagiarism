bool WasmValidator::validate(Module& module, FeatureSet features, Flags flags) {
  ValidationInfo info;
  info.validateWeb = (flags & Web) != 0;
  info.validateGlobally = (flags & Globally) != 0;
  info.features = features;
  info.quiet = (flags & Quiet) != 0;
  // parallel wasm logic validation
  PassRunner runner(&module);
  runner.add<FunctionValidator>(&info);
  runner.setIsNested(true);
  runner.run();
  // validate globally
  if (info.validateGlobally) {
    validateImports(module, info);
    validateExports(module, info);
    validateGlobals(module, info);
    validateMemory(module, info);
    validateTable(module, info);
    validateModule(module, info);
  }
  // validate additional internal IR details when in pass-debug mode
  if (PassRunner::getPassDebug()) {
    validateBinaryenIR(module, info);
  }
  // print all the data
  if (!info.valid.load() && !info.quiet) {
    for (auto& func : module.functions) {
      std::cerr << info.getStream(func.get()).str();
    }
    std::cerr << info.getStream(nullptr).str();
  }
  return info.valid.load();
}