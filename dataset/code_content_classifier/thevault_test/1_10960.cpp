void IntSimdMatrix::Init(const GENERIC_2D_ARRAY<int8_t> &w, std::vector<int8_t> &shaped_w,
                         int32_t &rounded_num_out) const {
  const int num_out = w.dim1();
  const int num_in = w.dim2() - 1;
  // The rounded-up sizes of the reshaped weight matrix, excluding biases.
  int rounded_num_in = Roundup(num_in, num_inputs_per_group_);
  rounded_num_out = RoundOutputs(num_out);
  // Add the bias and compute the required size.
  shaped_w.resize((rounded_num_in + 1) * rounded_num_out, 0);
  int shaped_index = 0;
  int output = 0;
  // Each number of registers needs a different format! Iterates over the
  // different numbers of registers (each a power of 2).
  for (int num_registers = max_output_registers_; num_registers >= 1; num_registers /= 2) {
    // The number of outputs that we will generate with this many registers.
    int num_outputs_per_register_set = num_registers * num_outputs_per_register_;
    // Use the max number of registers until we have to go fewer.
    while (output + num_outputs_per_register_set <= rounded_num_out) {
      // Accumulating outputs in registers saves iterating over the inputs, so
      // we only have to do it once per output register set.
      for (int input = 0; input < num_in; input += num_inputs_per_group_) {
        // Iterate over the number of outputs in a register set.
        for (int j = 0; j < num_outputs_per_register_set; ++j) {
          // Inner-most loop corresponds to the number of inputs in an input
          // group.
          for (int i = 0; i < num_inputs_per_group_; ++i) {
            int8_t weight = 0;
            if (output + j < num_out && input + i < num_in) {
              weight = w(output + j, input + i);
            }
            shaped_w[shaped_index++] = weight;
          }
        }
      }
      // Append the bias weights for the register set.
      for (int j = 0; j < num_outputs_per_register_set; ++j) {
        int8_t weight = 0;
        if (output + j < num_out) {
          weight = w(output + j, num_in);
        }
        shaped_w[shaped_index++] = weight;
      }
      output += num_outputs_per_register_set;
    }
  }
}