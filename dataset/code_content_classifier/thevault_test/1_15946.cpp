BOOST_AUTO_TEST_CASE(AtrousConvolutionLayerParametersTest)
{
  // Parameter order for the constructor: inSize, outSize, kW, kH, dW, dH, padW,
  // padH, inputWidth, inputHeight, dilationW, dilationH, paddingType ("none").
  AtrousConvolution<> layer1(1, 2, 3, 4, 5, 6, std::make_tuple(7, 8),
      std::make_tuple(9, 10), 11, 12, 13, 14);
  AtrousConvolution<> layer2(2, 3, 4, 5, 6, 7, std::make_tuple(8, 9),
      std::make_tuple(10, 11), 12, 13, 14, 15);

  // Make sure we can get the parameters successfully.
  BOOST_REQUIRE_EQUAL(layer1.InputWidth(), 11);
  BOOST_REQUIRE_EQUAL(layer1.InputHeight(), 12);
  BOOST_REQUIRE_EQUAL(layer1.KernelWidth(), 3);
  BOOST_REQUIRE_EQUAL(layer1.KernelHeight(), 4);
  BOOST_REQUIRE_EQUAL(layer1.StrideWidth(), 5);
  BOOST_REQUIRE_EQUAL(layer1.StrideHeight(), 6);
  BOOST_REQUIRE_EQUAL(layer1.Padding().PadHTop(), 9);
  BOOST_REQUIRE_EQUAL(layer1.Padding().PadHBottom(), 10);
  BOOST_REQUIRE_EQUAL(layer1.Padding().PadWLeft(), 7);
  BOOST_REQUIRE_EQUAL(layer1.Padding().PadWRight(), 8);
  BOOST_REQUIRE_EQUAL(layer1.DilationWidth(), 13);
  BOOST_REQUIRE_EQUAL(layer1.DilationHeight(), 14);

  // Now modify the parameters to match the second layer.
  layer1.InputWidth() = 12;
  layer1.InputHeight() = 13;
  layer1.KernelWidth() = 4;
  layer1.KernelHeight() = 5;
  layer1.StrideWidth() = 6;
  layer1.StrideHeight() = 7;
  layer1.Padding().PadHTop() = 10;
  layer1.Padding().PadHBottom() = 11;
  layer1.Padding().PadWLeft() = 8;
  layer1.Padding().PadWRight() = 9;
  layer1.DilationWidth() = 14;
  layer1.DilationHeight() = 15;

  // Now ensure all results are the same.
  BOOST_REQUIRE_EQUAL(layer1.InputWidth(), layer2.InputWidth());
  BOOST_REQUIRE_EQUAL(layer1.InputHeight(), layer2.InputHeight());
  BOOST_REQUIRE_EQUAL(layer1.KernelWidth(), layer2.KernelWidth());
  BOOST_REQUIRE_EQUAL(layer1.KernelHeight(), layer2.KernelHeight());
  BOOST_REQUIRE_EQUAL(layer1.StrideWidth(), layer2.StrideWidth());
  BOOST_REQUIRE_EQUAL(layer1.StrideHeight(), layer2.StrideHeight());
  BOOST_REQUIRE_EQUAL(layer1.Padding().PadHTop(), layer2.Padding().PadHTop());
  BOOST_REQUIRE_EQUAL(layer1.Padding().PadHBottom(),
                      layer2.Padding().PadHBottom());
  BOOST_REQUIRE_EQUAL(layer1.Padding().PadWLeft(),
                      layer2.Padding().PadWLeft());
  BOOST_REQUIRE_EQUAL(layer1.Padding().PadWRight(),
                      layer2.Padding().PadWRight());
  BOOST_REQUIRE_EQUAL(layer1.DilationWidth(), layer2.DilationWidth());
  BOOST_REQUIRE_EQUAL(layer1.DilationHeight(), layer2.DilationHeight());
}