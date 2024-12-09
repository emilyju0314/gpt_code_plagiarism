ParameterOptimizer* OptimizerWithRegularizer::create(
    const OptimizationConfig& optConfig,
    const ParameterConfig& paraConfig,
    bool isParameterSparse,
    bool inPserver) {
  ParameterOptimizer* optimizer =
      ParameterOptimizer::create(optConfig, inPserver);
  if ((optConfig.gradient_clipping_threshold() > 0.0f ||
       paraConfig.gradient_clipping_threshold() > 0.0f) &&
      !dynamic_cast<AddOptimizer*>(optimizer)) {
    optimizer = new OptimizerWithGradientClipping(optConfig, optimizer);
  }
  Regularizer* regularizer =
      Regularizer::get(optimizer->getParameterTypes(), paraConfig);
  if (!regularizer) {
    return optimizer;
  }

  if (paraConfig.num_batches_regularization() > 1) {
    if (optConfig.num_batches_per_send_parameter() > 1) {
      CHECK_EQ(optConfig.num_batches_per_send_parameter() %
                   paraConfig.num_batches_regularization(),
               0)
          << "regularization should be apply in sending batch";
    }
    CHECK(paraConfig.momentum() == 0.0f) << "Parameter cannot support momentum "
                                            "if num_batches_regularization set";

    if (optConfig.center_parameter_update_method() == "average" &&
        optConfig.num_batches_per_send_parameter() ==
            paraConfig.num_batches_regularization()) {
      LOG(INFO) << "decay in pserver and no decay in trainer";
      if (inPserver) {  // decay in pserver
        optimizer->setNoDecay();
        return new OptimizerWithRegularizer(optConfig, optimizer, regularizer);
      }
      // no decay in trainer
      optimizer->setNoDecay();
      return optimizer;
    }
    if (dynamic_cast<AddOptimizer*>(optimizer)) {
      return optimizer;  // normal average, no decay in pserver
    }
    // normal
    optimizer->setNoDecay();
    return new OptimizerWithRegularizerEveryNumBatches(
        optConfig, optimizer, regularizer);
  }
  if (isParameterSparse) {
    CHECK(paraConfig.momentum() == 0.0f)
        << "Parameter cannot support momentum if it's sparse.";
    optimizer->setNoDecay();
    return new OptimizerWithRegularizerSparse(
        optConfig, optimizer, regularizer);
  }
  // dense
  if (paraConfig.decay_rate_l1() == 0.0f ||
      dynamic_cast<AddOptimizer*>(optimizer)) {
    return optimizer;
  }
  CHECK(paraConfig.momentum() == 0.0f)
      << "Parameter cannot support momentum if it use L1 decay.";
  optimizer->setNoDecay();
  return new OptimizerWithRegularizer(optConfig, optimizer, regularizer);
}