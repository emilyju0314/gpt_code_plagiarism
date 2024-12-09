BOOST_AUTO_TEST_CASE(DecisionRegularisationTest)
{
  arma::mat inputData;
  DatasetInfo info;
  if (!data::Load("braziltourism.arff", inputData, info))
    BOOST_FAIL("Cannot load train dataset braziltourism.arff!");

  arma::Row<size_t> labels;
  if (!data::Load("braziltourism_labels.txt", labels))
    BOOST_FAIL("Cannot load labels for braziltourism_labels.txt");

  // Initialize an all-ones weight matrix.
  arma::mat weights(1, labels.n_cols, arma::fill::ones);

  // Input training data.
  SetInputParam("training", std::make_tuple(info, inputData));
  SetInputParam("labels", labels);
  SetInputParam("weights", weights);

  SetInputParam("minimum_gain_split", 1e-7);

  // Input test data.
  SetInputParam("test", std::make_tuple(info, inputData));
  arma::Row<size_t> pred;
  mlpackMain();
  pred = std::move(CLI::GetParam<arma::Row<size_t>>("predictions"));

  // Input training data.
  SetInputParam("training", std::make_tuple(info, inputData));
  SetInputParam("labels", std::move(labels));
  SetInputParam("weights", std::move(weights));

  SetInputParam("minimum_gain_split", 0.01);

  // Input test data.
  SetInputParam("test", std::move(std::make_tuple(info, inputData)));
  arma::Row<size_t> predRegularised;
  mlpackMain();
  predRegularised = std::move(CLI::GetParam<arma::Row<size_t>>("predictions"));

  size_t count = 0;
  // This part of code is dupliacte with no weighted one.
  for (size_t i = 0; i < 1000; ++i)
  {
    if (pred[i] != predRegularised[i])
      count++;
  }

  BOOST_REQUIRE_GT(count, 0);
}