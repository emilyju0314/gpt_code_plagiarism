BOOST_AUTO_TEST_CASE(WriteCellStateParamLSTMLayerTest)
{
  const size_t rho = 5, inputSize = 3, outputSize = 2;

  // Provide input of all ones.
  arma::cube input = arma::ones(inputSize, outputSize, rho);

  arma::mat inputGate, forgetGate, outputGate, hidden;
  arma::mat outLstm, cellLstm;
  arma::mat cellCalc;

  // LSTM layer.
  LSTM<> lstm(inputSize, outputSize, rho);
  lstm.Reset();
  lstm.ResetCell(rho);

  // Initialize the weights to all ones.
  lstm.Parameters().ones();

  arma::mat inputWeight = arma::ones(outputSize, inputSize);
  arma::mat outputWeight = arma::ones(outputSize, outputSize);
  arma::mat bias = arma::ones(outputSize, input.n_cols);
  arma::mat outCalc = arma::zeros(outputSize, input.n_cols);

  for (size_t seqNum = 0; seqNum < rho; ++seqNum)
  {
      // Wrap a matrix around our data to avoid a copy.
      arma::mat stepData(input.slice(seqNum).memptr(),
          input.n_rows, input.n_cols, false, true);

      if (cellLstm.is_empty())
      {
        // Set the cell state to zeros.
        cellLstm = arma::zeros(outputSize, input.n_cols);
        cellCalc = arma::zeros(outputSize, input.n_cols);
      }
      else
      {
        // Set the cell state to zeros.
        cellLstm = arma::zeros(cellLstm.n_rows, cellLstm.n_cols);
        cellCalc = arma::zeros(cellCalc.n_rows, cellCalc.n_cols);
      }

      // Apply Forward() on the LSTM layer.
      lstm.Forward(stepData, // Input.
                   outLstm,  // Output.
                   cellLstm, // Cell state.
                   true);  // Write into cell state.

      // Compute the value of cell state and output.
      // i = sigmoid(W.dot(x) + W.dot(h) + W.dot(c) + b).
      inputGate = 1.0 /(1 + arma::exp(-(inputWeight * stepData +
          outputWeight * outCalc + outputWeight % cellCalc + bias)));

      // f = sigmoid(W.dot(x) + W.dot(h) + W.dot(c) + b).
      forgetGate = 1.0 /(1 + arma::exp(-(inputWeight * stepData +
          outputWeight * outCalc + outputWeight % cellCalc + bias)));

      // z = tanh(W.dot(x) + W.dot(h) + b).
      hidden = arma::tanh(inputWeight * stepData +
                     outputWeight * outCalc + bias);

      // c = f * c + i * z.
      cellCalc = forgetGate % cellCalc + inputGate % hidden;

      // o = sigmoid(W.dot(x) + W.dot(h) + W.dot(c) + b).
      outputGate = 1.0 /(1 + arma::exp(-(inputWeight * stepData +
          outputWeight * outCalc + outputWeight % cellCalc + bias)));

      // h = o * tanh(c).
      outCalc = outputGate % arma::tanh(cellCalc);

      CheckMatrices(outLstm, outCalc, 1e-12);
      CheckMatrices(cellLstm, cellCalc, 1e-12);
  }

  // Attempting to write empty matrix into cell state.
  lstm.Reset();
  lstm.ResetCell(rho);
  arma::mat stepData(input.slice(0).memptr(),
      input.n_rows, input.n_cols, false, true);

  lstm.Forward(stepData, // Input.
               outLstm,  // Output.
               cellLstm, // Cell state.
               true); // Write into cell state.

  for (size_t seqNum = 1; seqNum < rho; ++seqNum)
  {
    arma::mat empty;
    // Should throw error.
    BOOST_REQUIRE_THROW(lstm.Forward(stepData, // Input.
                                     outLstm,  // Output.
                                     empty, // Cell state.
                                     true),  // Write into cell state.
                                     std::runtime_error);
  }
}