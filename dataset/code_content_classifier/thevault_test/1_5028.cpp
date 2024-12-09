Channel* BioFactory::InstantiateChannelFromLayout(
    const Channel_Layout& channel_layout, const int32& rand_seed) {

  Channel* result = NULL;
  switch (channel_layout.type()) {
    case CH_TYPE_IKNA:
      result = new IKNaChannel();
      break;
    case CH_TYPE_INAP:
      result = new INaPChannel();
      break;
      return NULL;
    case CH_TYPE_IH:
      result = new IhChannel();
      break;
      return NULL;
  }

  if (!::google::protobuf::TextFormat::ParseFromString(
      channel_layout.common_params(), result->get_common_params())) {
    printf("ERROR: BF-CHAN] Couldn't parse neuron's common parameters\n");
    delete result;
    return NULL;
  }

  if (!::google::protobuf::TextFormat::ParseFromString(channel_layout.state(),
                                                       result->get_state())) {
    printf("ERROR: BF-CHAN] Couldn't parse neuron's state");
    delete result;
    return NULL;
  }

  result->get_common_params()->set_random_seed(rand_seed);

  result->get_common_params()->set_uuid(GetNewUUID());

  return result;
}