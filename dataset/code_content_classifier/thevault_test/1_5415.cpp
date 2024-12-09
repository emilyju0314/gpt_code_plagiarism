void doOneExpandTest(string trans_type,
                     bool hasSubseq,
                     bool useGpu,
                     Argument& input1,
                     Argument& input2,
                     Argument& result) {
  FLAGS_use_gpu = false;
  // Setting up the expand layer
  TestConfig config;
  config.layerConfig.set_type("expand");

  auto inputType1 =
      trans_type == "non-seq" ? INPUT_DENSE_DIM_DATA : INPUT_SEQUENCE_DATA;
  config.inputDefs.push_back({inputType1, "layer0", 1, 0});
  auto inputType2 =
      hasSubseq ? INPUT_HASSUB_SEQUENCE_DATA : INPUT_SEQUENCE_DATA;

  config.inputDefs.push_back({inputType2, "layer1", 1, 0});
  config.layerConfig.add_inputs();
  config.layerConfig.add_inputs();
  config.layerConfig.set_trans_type(trans_type);

  // data layer initialize
  std::vector<DataLayerPtr> dataLayers;
  LayerMap layerMap;
  vector<Argument> datas;
  initDataLayer(
      config, &dataLayers, &datas, &layerMap, "expand", 1, false, useGpu);
  dataLayers[0]->getOutput() = input1;
  dataLayers[1]->getOutput() = input2;

  // test layer initialize
  std::vector<ParameterPtr> parameters;
  LayerPtr expandLayer;
  initTestLayer(config, &layerMap, &parameters, &expandLayer);
  expandLayer->forward(PASS_GC);
  checkMatrixEqual(expandLayer->getOutputValue(), result.value);
}