Network *NetworkBuilder::ParseLSTM(const StaticShape &input_shape, const char **str) {
  bool two_d = false;
  NetworkType type = NT_LSTM;
  const char *spec_start = *str;
  int chars_consumed = 1;
  int num_outputs = 0;
  char key = (*str)[chars_consumed], dir = 'f', dim = 'x';
  if (key == 'S') {
    type = NT_LSTM_SOFTMAX;
    num_outputs = num_softmax_outputs_;
    ++chars_consumed;
  } else if (key == 'E') {
    type = NT_LSTM_SOFTMAX_ENCODED;
    num_outputs = num_softmax_outputs_;
    ++chars_consumed;
  } else if (key == '2' &&
             (((*str)[2] == 'x' && (*str)[3] == 'y') || ((*str)[2] == 'y' && (*str)[3] == 'x'))) {
    chars_consumed = 4;
    dim = (*str)[3];
    two_d = true;
  } else if (key == 'f' || key == 'r' || key == 'b') {
    dir = key;
    dim = (*str)[2];
    if (dim != 'x' && dim != 'y') {
      tprintf("Invalid dimension (x|y) in L Spec!:%s\n", *str);
      return nullptr;
    }
    chars_consumed = 3;
    if ((*str)[chars_consumed] == 's') {
      ++chars_consumed;
      type = NT_LSTM_SUMMARY;
    }
  } else {
    tprintf("Invalid direction (f|r|b) in L Spec!:%s\n", *str);
    return nullptr;
  }
  char *end;
  int num_states = strtol(*str + chars_consumed, &end, 10);
  if (num_states <= 0) {
    tprintf("Invalid number of states in L Spec!:%s\n", *str);
    return nullptr;
  }
  *str = end;
  Network *lstm = nullptr;
  if (two_d) {
    lstm = BuildLSTMXYQuad(input_shape.depth(), num_states);
  } else {
    if (num_outputs == 0) {
      num_outputs = num_states;
    }
    std::string name(spec_start, *str - spec_start);
    lstm = new LSTM(name, input_shape.depth(), num_states, num_outputs, false, type);
    if (dir != 'f') {
      auto *rev = new Reversed("RevLSTM", NT_XREVERSED);
      rev->SetNetwork(lstm);
      lstm = rev;
    }
    if (dir == 'b') {
      name += "LTR";
      auto *parallel = new Parallel("BidiLSTM", NT_PAR_RL_LSTM);
      parallel->AddToStack(
          new LSTM(name, input_shape.depth(), num_states, num_outputs, false, type));
      parallel->AddToStack(lstm);
      lstm = parallel;
    }
  }
  if (dim == 'y') {
    auto *rev = new Reversed("XYTransLSTM", NT_XYTRANSPOSE);
    rev->SetNetwork(lstm);
    lstm = rev;
  }
  return lstm;
}