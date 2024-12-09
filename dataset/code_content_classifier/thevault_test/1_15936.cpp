BOOST_AUTO_TEST_CASE(ConcatAlongAxisTest)
{
  arma::mat output, input, error, outputA, outputB;
  size_t inputWidth = 4, inputHeight = 4, inputChannel = 2;
  size_t outputWidth, outputHeight, outputChannel = 2;
  size_t kW = 3, kH = 3;
  size_t batch = 1;

  // Using Convolution<> layer as inout to Concat<> layer.
  // Compute the output shape of convolution layer.
  outputWidth  = (inputWidth - kW) + 1;
  outputHeight = (inputHeight - kH) + 1;

  input = arma::ones(inputWidth * inputHeight * inputChannel, batch);

  Convolution<> moduleA(inputChannel, outputChannel, kW, kH, 1, 1, 0, 0,
      inputWidth, inputHeight);
  Convolution<> moduleB(inputChannel, outputChannel, kW, kH, 1, 1, 0, 0,
      inputWidth, inputHeight);

  moduleA.Reset();
  moduleA.Parameters().randu();
  moduleB.Reset();
  moduleB.Parameters().randu();

  // Compute output of each layer.
  moduleA.Forward(input, outputA);
  moduleB.Forward(input, outputB);

  arma::cube A(outputA.memptr(), outputWidth, outputHeight, outputChannel);
  arma::cube B(outputB.memptr(), outputWidth, outputHeight, outputChannel);

  error = arma::ones(outputWidth * outputHeight * outputChannel * 2, 1);

  for (size_t axis = 0; axis < 3; ++axis)
  {
    size_t x = 1, y = 1, z = 1;
    arma::cube calculatedOut;
    if (axis == 0)
    {
      calculatedOut.set_size(2 * outputWidth, outputHeight, outputChannel);
      for (size_t i = 0; i < A.n_slices; ++i)
      {
          arma::mat aMat = A.slice(i);
          arma::mat bMat = B.slice(i);
          calculatedOut.slice(i) = arma::join_cols(aMat, bMat);
      }
      x = 2;
    }
    if (axis == 1)
    {
      calculatedOut.set_size(outputWidth, 2 * outputHeight, outputChannel);
      for (size_t i = 0; i < A.n_slices; ++i)
      {
          arma::mat aMat = A.slice(i);
          arma::mat bMat = B.slice(i);
          calculatedOut.slice(i) = arma::join_rows(aMat, bMat);
      }
      y = 2;
    }
    if (axis == 2)
    {
      calculatedOut = arma::join_slices(A, B);
      z = 2;
    }

    // Compute output of Concat<> layer.
    arma::Row<size_t> inputSize{outputWidth, outputHeight, outputChannel};
    Concat<> module(inputSize, axis);
    module.Add(moduleA);
    module.Add(moduleB);
    module.Forward(input, output);
    arma::cube concatOut(output.memptr(), x * outputWidth,
        y * outputHeight, z * outputChannel);

    // Verify if the output reshaped to cubes are similar.
    CheckMatrices(concatOut, calculatedOut, 1e-12);
  }
}