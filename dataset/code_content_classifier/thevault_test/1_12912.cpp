BOOST_AUTO_TEST_CASE(ssRBMTest)
{
  arma::mat data;
  size_t hiddenLayerSize = 5;
  data.randu(3, 100);
  double slabPenalty = 1;
  double tempRadius, radius = arma::norm(data.col(0));
  for (size_t i = 1; i < data.n_cols; i++)
  {
    tempRadius = arma::norm(data.col(i));
    if (radius < tempRadius)
      radius = tempRadius;
  }

  size_t poolSize = 1;

  GaussianInitialization gaussian(0, 0.1);
  RBM<GaussianInitialization, arma::mat, SpikeSlabRBM> Rbm(data, gaussian,
      data.n_rows, hiddenLayerSize, 1, 1, 1, poolSize, slabPenalty, radius,
      true);
  RBM<GaussianInitialization, arma::mat, SpikeSlabRBM> RbmXml(data, gaussian,
      data.n_rows, hiddenLayerSize, 1, 1, 1, poolSize, slabPenalty, radius,
      true);
  RBM<GaussianInitialization, arma::mat, SpikeSlabRBM> RbmText(data, gaussian,
      data.n_rows, hiddenLayerSize, 1, 1, 1, poolSize, slabPenalty, radius,
      true);
  RBM<GaussianInitialization, arma::mat, SpikeSlabRBM> RbmBinary(data, gaussian,
      data.n_rows, hiddenLayerSize, 1, 1, 1, poolSize, slabPenalty, radius,
      true);
  Rbm.Reset();
  Rbm.VisiblePenalty().fill(15);
  Rbm.SpikeBias().ones();

  SerializeObjectAll(Rbm, RbmXml, RbmText, RbmBinary);
  CheckMatrices(Rbm.Parameters(), RbmXml.Parameters(), RbmText.Parameters(),
      RbmBinary.Parameters());

  CheckMatrices(Rbm.VisiblePenalty(), RbmXml.VisiblePenalty());
  CheckMatrices(Rbm.VisiblePenalty(), RbmText.VisiblePenalty());
  CheckMatrices(Rbm.VisiblePenalty(), RbmBinary.VisiblePenalty());

  CheckMatrices(Rbm.SpikeBias(), RbmXml.SpikeBias());
  CheckMatrices(Rbm.SpikeBias(), RbmText.SpikeBias());
  CheckMatrices(Rbm.SpikeBias(), RbmBinary.SpikeBias());

  CheckMatrices(Rbm.Weight(), RbmXml.Weight());
  CheckMatrices(Rbm.Weight(), RbmText.Weight());
  CheckMatrices(Rbm.Weight(), RbmBinary.Weight());
}