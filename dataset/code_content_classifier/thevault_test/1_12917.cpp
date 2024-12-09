BOOST_AUTO_TEST_CASE(AdaBoostTrainingDataOrModelTest)
{
  arma::mat trainData;
  if (!data::Load("trainSet.csv", trainData))
    BOOST_FAIL("Unable to load train dataset trainSet.csv!");

  SetInputParam("training", std::move(trainData));

  mlpackMain();

  SetInputParam("input_model",
                CLI::GetParam<AdaBoostModel*>("output_model"));

  Log::Fatal.ignoreInput = true;
  BOOST_REQUIRE_THROW(mlpackMain(), std::runtime_error);
  Log::Fatal.ignoreInput = false;
}