BOOST_AUTO_TEST_CASE(AdaBoostWeakLearnerTest)
{
  arma::mat trainData;
  if (!data::Load("trainSet.csv", trainData))
    BOOST_FAIL("Unable to load train dataset trainSet.csv!");

  SetInputParam("training", std::move(trainData));
  SetInputParam("weak_learner", std::string("decision tree"));

  Log::Fatal.ignoreInput = true;
  BOOST_REQUIRE_THROW(mlpackMain(), std::runtime_error);
  Log::Fatal.ignoreInput = false;
}