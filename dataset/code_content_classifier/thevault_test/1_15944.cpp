BOOST_AUTO_TEST_CASE(GradientTransposedConvolutionLayerTest)
{
  // Add function gradient instantiation.
  // To make this test robust, check it five times.
  bool pass = false;
  for (size_t trial = 0; trial < 5; trial++)
  {
    struct GradientFunction
    {
      GradientFunction()
      {
        input = arma::linspace<arma::colvec>(0, 35, 36);
        target = arma::mat("1");

        model = new FFN<NegativeLogLikelihood<>, RandomInitialization>();
        model->Predictors() = input;
        model->Responses() = target;
        model->Add<TransposedConvolution<> >
            (1, 1, 3, 3, 2, 2, 1, 1, 6, 6, 12, 12);
        model->Add<LogSoftMax<> >();
      }

      ~GradientFunction()
      {
        delete model;
      }

      double Gradient(arma::mat& gradient) const
      {
        double error = model->Evaluate(model->Parameters(), 0, 1);
        model->Gradient(model->Parameters(), 0, gradient, 1);
        return error;
      }

      arma::mat& Parameters() { return model->Parameters(); }

      FFN<NegativeLogLikelihood<>, RandomInitialization>* model;
      arma::mat input, target;
    } function;

    if (CheckGradient(function) < 1e-3)
    {
      pass = true;
      break;
    }
  }
  BOOST_REQUIRE_EQUAL(pass, true);
}