BOOST_AUTO_TEST_CASE(ReadCellStateParamLSTMLayerTest)
{
  const size_t rho = 5, inputSize = 3, outputSize = 2;

  // Provide input of all ones.
  arma::cube input = arma::ones(inputSize, outputSize, rho);

  arma::mat inputGate, forgetGate, outputGate, hidden;
  arma::mat outLstm, cellLstm;

  // LSTM layer.
  LSTM<> lstm(inputSize, outputSize, rho);
  lstm.Reset();
  lstm.ResetCell(rho);

  // Initialize the weights to all ones.
  lstm.Parameters().ones();

  arma::mat inputWeight = arma::ones(outputSize, inputSize);
  arma::mat outputWeight = arma::ones(outputSize, outputSize);
  arma::mat bias = arma::ones(outputSize, input.n_cols);
  arma::mat cellCalc = arma::zeros(outputSize, input.n_cols);
  arma::mat outCalc = arma::zeros(outputSize, input.n_cols);

  for (size_t seqNum = 0; seqNum < rho; ++seqNum)
  {
      // Wrap a matrix around our data to avoid a copy.
      arma::mat stepData(input.slice(seqNum).memptr(),
          input.n_rows, input.n_cols, false, true);

      // Apply Forward() on LSTM layer.
      lstm.Forward(stepData, // Input.
                   outLstm,  // Output.
                   cellLstm, // Cell state.
                   false); // Don't write into the cell state.

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
}