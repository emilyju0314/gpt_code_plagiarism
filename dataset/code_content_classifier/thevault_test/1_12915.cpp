BOOST_AUTO_TEST_CASE(AdaBoostItrTest)
{
  arma::mat trainData;
  if (!data::Load("trainSet.csv", trainData))
    BOOST_FAIL("Unable load train dataset trainSet.csv!");

  SetInputParam("training", std::move(trainData));
  SetInputParam("iterations", (int) -1);

  Log::Fatal.ignoreInput = true;
  BOOST_REQUIRE_THROW(mlpackMain(), std::runtime_error);
  Log::Fatal.ignoreInput = false;
}