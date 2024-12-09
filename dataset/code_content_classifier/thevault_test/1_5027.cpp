Neuron* BioFactory::InstantiateNeuronFromLayout(
    const Neuron_Layout& neuron_layout, const int32& rand_seed) {

  Neuron* result = NULL;

  switch (neuron_layout.type()) {
    case N_TYPE_PIAF:
      result = new PulseIntegrateAndFire();
      break;
  }

  if (!::google::protobuf::TextFormat::ParseFromString(
      neuron_layout.common_params(), result->get_common_params())) {
    printf("ERROR: [BF-NEURON] Couldn't parse neuron's common parameters\n");
    delete result;
    return NULL;
  }

  if (!::google::protobuf::TextFormat::ParseFromString(neuron_layout.state(),
                                                       result->get_state())) {
    printf("ERROR: [BF-NEURON] Couldn't parse neuron's state\n");
    delete result;
    return NULL;
  }

  result->get_common_params()->set_random_seed(rand_seed);

  result->get_common_params()->set_uuid(GetNewUUID());

  return result;
}