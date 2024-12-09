BOOST_AUTO_TEST_CASE(ConvolutionLayerParametersTest)
{
  // Parameter order: inSize, outSize, kW, kH, dW, dH, padW, padH, inputWidth,
  // inputHeight, paddingType.
  Convolution<> layer1(1, 2, 3, 4, 5, 6, std::tuple<size_t, size_t>(7, 8),
      std::tuple<size_t, size_t>(9, 10), 11, 12, "none");
  Convolution<> layer2(2, 3, 4, 5, 6, 7, std::tuple<size_t, size_t>(8, 9),
      std::tuple<size_t, size_t>(10, 11), 12, 13, "none");

  // Make sure we can get the parameters successfully.
  BOOST_REQUIRE_EQUAL(layer1.InputWidth(), 11);
  BOOST_REQUIRE_EQUAL(layer1.InputHeight(), 12);
  BOOST_REQUIRE_EQUAL(layer1.KernelWidth(), 3);
  BOOST_REQUIRE_EQUAL(layer1.KernelHeight(), 4);
  BOOST_REQUIRE_EQUAL(layer1.StrideWidth(), 5);
  BOOST_REQUIRE_EQUAL(layer1.StrideHeight(), 6);
  BOOST_REQUIRE_EQUAL(layer1.PadWLeft(), 7);
  BOOST_REQUIRE_EQUAL(layer1.PadWRight(), 8);
  BOOST_REQUIRE_EQUAL(layer1.PadHTop(), 9);
  BOOST_REQUIRE_EQUAL(layer1.PadHBottom(), 10);

  // Now modify the parameters to match the second layer.
  layer1.InputWidth() = 12;
  layer1.InputHeight() = 13;
  layer1.KernelWidth() = 4;
  layer1.KernelHeight() = 5;
  layer1.StrideWidth() = 6;
  layer1.StrideHeight() = 7;
  layer1.PadWLeft() = 8;
  layer1.PadWRight() = 9;
  layer1.PadHTop() = 10;
  layer1.PadHBottom() = 11;

  // Now ensure all results are the same.
  BOOST_REQUIRE_EQUAL(layer1.InputWidth(), layer2.InputWidth());
  BOOST_REQUIRE_EQUAL(layer1.InputHeight(), layer2.InputHeight());
  BOOST_REQUIRE_EQUAL(layer1.KernelWidth(), layer2.KernelWidth());
  BOOST_REQUIRE_EQUAL(layer1.KernelHeight(), layer2.KernelHeight());
  BOOST_REQUIRE_EQUAL(layer1.StrideWidth(), layer2.StrideWidth());
  BOOST_REQUIRE_EQUAL(layer1.StrideHeight(), layer2.StrideHeight());
  BOOST_REQUIRE_EQUAL(layer1.PadWLeft(), layer2.PadWLeft());
  BOOST_REQUIRE_EQUAL(layer1.PadWRight(), layer2.PadWRight());
  BOOST_REQUIRE_EQUAL(layer1.PadHTop(), layer2.PadHTop());
  BOOST_REQUIRE_EQUAL(layer1.PadHBottom(), layer2.PadHBottom());
}