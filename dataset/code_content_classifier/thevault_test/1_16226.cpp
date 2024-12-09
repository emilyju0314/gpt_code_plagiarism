void StandardZOA::calculateElementVectorImpl(ElInfo const* elInfo, DenseVector<double>& vec)
  {
    int nPoints = quadrature->getNumPoints();
    DenseVector<double> c(nPoints, 0.0);

    for (auto& term : terms)
      (static_cast<ZeroOrderTerm*>(term))->getC(elInfo, nPoints, c);

    for (int iq = 0; iq < nPoints; iq++)
    {
      c[iq] *= elInfo->getDet();

      for (int i = 0; i < nRow; i++)
      {
        double psi = (*(rowFeSpace->getBasisFcts()->getPhi(i)))
                     (quadrature->getLambda(iq));
        vec[i] += quadrature->getWeight(iq) * c[iq] * psi;
      }
    }
  }