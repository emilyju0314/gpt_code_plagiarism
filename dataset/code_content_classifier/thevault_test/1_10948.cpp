Network *Network::CreateFromFile(TFile *fp) {
  NetworkType type;       // Type of the derived network class.
  TrainingState training; // Are we currently training?
  bool needs_to_backprop; // This network needs to output back_deltas.
  int32_t network_flags;  // Behavior control flags in NetworkFlags.
  int32_t ni;             // Number of input values.
  int32_t no;             // Number of output values.
  int32_t num_weights;    // Number of weights in this and sub-network.
  std::string name;       // A unique name for this layer.
  int8_t data;
  Network *network = nullptr;
  type = getNetworkType(fp);
  if (!fp->DeSerialize(&data)) {
    return nullptr;
  }
  training = data == TS_ENABLED ? TS_ENABLED : TS_DISABLED;
  if (!fp->DeSerialize(&data)) {
    return nullptr;
  }
  needs_to_backprop = data != 0;
  if (!fp->DeSerialize(&network_flags)) {
    return nullptr;
  }
  if (!fp->DeSerialize(&ni)) {
    return nullptr;
  }
  if (!fp->DeSerialize(&no)) {
    return nullptr;
  }
  if (!fp->DeSerialize(&num_weights)) {
    return nullptr;
  }
  if (!fp->DeSerialize(name)) {
    return nullptr;
  }

  switch (type) {
    case NT_CONVOLVE:
      network = new Convolve(name.c_str(), ni, 0, 0);
      break;
    case NT_INPUT:
      network = new Input(name.c_str(), ni, no);
      break;
    case NT_LSTM:
    case NT_LSTM_SOFTMAX:
    case NT_LSTM_SOFTMAX_ENCODED:
    case NT_LSTM_SUMMARY:
      network = new LSTM(name.c_str(), ni, no, no, false, type);
      break;
    case NT_MAXPOOL:
      network = new Maxpool(name.c_str(), ni, 0, 0);
      break;
    // All variants of Parallel.
    case NT_PARALLEL:
    case NT_REPLICATED:
    case NT_PAR_RL_LSTM:
    case NT_PAR_UD_LSTM:
    case NT_PAR_2D_LSTM:
      network = new Parallel(name.c_str(), type);
      break;
    case NT_RECONFIG:
      network = new Reconfig(name.c_str(), ni, 0, 0);
      break;
    // All variants of reversed.
    case NT_XREVERSED:
    case NT_YREVERSED:
    case NT_XYTRANSPOSE:
      network = new Reversed(name.c_str(), type);
      break;
    case NT_SERIES:
      network = new Series(name.c_str());
      break;
    case NT_TENSORFLOW:
#ifdef INCLUDE_TENSORFLOW
      network = new TFNetwork(name.c_str());
#else
      tprintf("TensorFlow not compiled in! -DINCLUDE_TENSORFLOW\n");
#endif
      break;
    // All variants of FullyConnected.
    case NT_SOFTMAX:
    case NT_SOFTMAX_NO_CTC:
    case NT_RELU:
    case NT_TANH:
    case NT_LINEAR:
    case NT_LOGISTIC:
    case NT_POSCLIP:
    case NT_SYMCLIP:
      network = new FullyConnected(name.c_str(), ni, no, type);
      break;
    default:
      break;
  }
  if (network) {
    network->training_ = training;
    network->needs_to_backprop_ = needs_to_backprop;
    network->network_flags_ = network_flags;
    network->num_weights_ = num_weights;
    if (!network->DeSerialize(fp)) {
      delete network;
      network = nullptr;
    }
  }
  return network;
}