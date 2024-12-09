void doOneDetectionOutputTest(MatrixPtr& inputLoc,
                              MatrixPtr& inputConf,
                              MatrixPtr& inputPriorBox,
                              size_t feature_map_width,
                              size_t feature_map_height,
                              real nms_threshold,
                              bool use_gpu,
                              MatrixPtr& result) {
  // Setting up the detection output layer
  TestConfig configt;
  configt.layerConfig.set_type("detection_output");
  LayerInputConfig* input = configt.layerConfig.add_inputs();
  configt.layerConfig.add_inputs();
  configt.layerConfig.add_inputs();

  DetectionOutputConfig* detOutput = input->mutable_detection_output_conf();
  detOutput->set_width(feature_map_width);
  detOutput->set_height(feature_map_height);
  detOutput->set_nms_threshold(nms_threshold);
  detOutput->set_num_classes(2);
  detOutput->set_nms_top_k(20);
  detOutput->set_keep_top_k(10);
  detOutput->set_background_id(0);
  detOutput->set_confidence_threshold(0.01);
  detOutput->set_input_num(1);
  configt.inputDefs.push_back({INPUT_DATA_TARGET, "priorbox", 32, 0});
  configt.inputDefs.push_back({INPUT_DATA, "input_loc", 16, 0});
  configt.inputDefs.push_back({INPUT_DATA, "input_conf", 8, 0});

  // data layer initialize
  std::vector<DataLayerPtr> dataLayers;
  LayerMap layerMap;
  vector<Argument> datas;
  initDataLayer(
      configt, &dataLayers, &datas, &layerMap, "priorbox", 1, false, use_gpu);

  dataLayers[0]->getOutputValue()->copyFrom(*inputPriorBox);
  dataLayers[1]->getOutputValue()->copyFrom(*inputLoc);
  dataLayers[2]->getOutputValue()->copyFrom(*inputConf);

  // test layer initialize
  bool store_FLAGS_use_gpu = FLAGS_use_gpu;
  FLAGS_use_gpu = use_gpu;
  std::vector<ParameterPtr> parameters;
  LayerPtr detectionOutputLayer;
  initTestLayer(configt, &layerMap, &parameters, &detectionOutputLayer);
  FLAGS_use_gpu = store_FLAGS_use_gpu;
  detectionOutputLayer->forward(PASS_GC);
  checkMatrixEqual(detectionOutputLayer->getOutputValue(), result);
}