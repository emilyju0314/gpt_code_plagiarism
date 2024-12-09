BOOST_AUTO_TEST_CASE(BinaryRBMTest)
{
  arma::mat data;
  size_t hiddenLayerSize = 5;
  data.randu(3, 100);

  GaussianInitialization gaussian(0, 0.1);
  RBM<GaussianInitialization> Rbm(data, gaussian, data.n_rows, hiddenLayerSize,
      1, 1, 1, 2, 8, 1, true);
  RBM<GaussianInitialization> RbmXml(data, gaussian, data.n_rows,
      hiddenLayerSize, 1, 1, 1, 2, 8, 1, true);
  RBM<GaussianInitialization> RbmText(data, gaussian, data.n_rows,
      hiddenLayerSize, 1, 1, 1, 2, 8, 1, true);
  RBM<GaussianInitialization> RbmBinary(data, gaussian, data.n_rows,
      hiddenLayerSize, 1, 1, 1, 2, 8, 1, true);
  Rbm.Reset();

  SerializeObjectAll(Rbm, RbmXml, RbmText, RbmBinary);
  CheckMatrices(Rbm.Parameters(), RbmXml.Parameters(), RbmText.Parameters(),
      RbmBinary.Parameters());
  CheckMatrices(Rbm.VisibleBias(), RbmXml.VisibleBias());
  CheckMatrices(Rbm.VisibleBias(), RbmText.VisibleBias());
  CheckMatrices(Rbm.VisibleBias(), RbmBinary.VisibleBias());

  CheckMatrices(Rbm.HiddenBias(), RbmXml.HiddenBias());
  CheckMatrices(Rbm.HiddenBias(), RbmText.HiddenBias());
  CheckMatrices(Rbm.HiddenBias(), RbmBinary.HiddenBias());

  CheckMatrices(Rbm.Weight(), RbmXml.Weight());
  CheckMatrices(Rbm.Weight(), RbmText.Weight());
  CheckMatrices(Rbm.Weight(), RbmBinary.Weight());
}