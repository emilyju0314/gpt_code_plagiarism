BOOST_AUTO_TEST_CASE(GradientHighwayLayerTest)
{
  // Linear function gradient instantiation.
  struct GradientFunction
  {
    GradientFunction()
    {
      input = arma::randu(5, 1);
      target = arma::mat("1");

      model = new FFN<NegativeLogLikelihood<>, NguyenWidrowInitialization>();
      model->Predictors() = input;
      model->Responses() = target;
      model->Add<IdentityLayer<> >();
      model->Add<Linear<> >(5, 10);

      highway = new Highway<>(10);
      highway->Add<Linear<> >(10, 10);
      highway->Add<ReLULayer<> >();
      highway->Add<Linear<> >(10, 10);
      highway->Add<ReLULayer<> >();

      model->Add(highway);
      model->Add<Linear<> >(10, 2);
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

    FFN<NegativeLogLikelihood<>, NguyenWidrowInitialization>* model;
    Highway<>* highway;
    arma::mat input, target;
  } function;

  BOOST_REQUIRE_LE(CheckGradient(function), 1e-4);
}