bool BundleObservation::setSolveSettings(BundleObservationSolveSettings solveSettings) {
    m_solveSettings = BundleObservationSolveSettingsQsp(
                        new BundleObservationSolveSettings(solveSettings));

    // initialize solution parameters for this observation
    int nCameraAngleCoefficients = m_solveSettings->numberCameraAngleCoefficientsSolved();
    int nCameraPositionCoefficients = m_solveSettings->numberCameraPositionCoefficientsSolved();

    int nParameters = 3*nCameraPositionCoefficients + 2*nCameraAngleCoefficients;
    if (nCameraAngleCoefficients >= 1 && m_solveSettings->solveTwist()) {
      nParameters += nCameraAngleCoefficients;
    }
    // size vectors and set to zero
    m_weights.resize(nParameters);
    m_weights.clear();
    m_corrections.resize(nParameters);
    m_corrections.clear();
//    m_solution.resize(nParameters);
//    m_solution.clear();
    m_adjustedSigmas.resize(nParameters);
    m_adjustedSigmas.clear();
    m_aprioriSigmas.resize(nParameters);
    for ( int i = 0; i < nParameters; i++) // initialize apriori sigmas to -1.0
      m_aprioriSigmas[i] = Isis::Null;

    if (!initParameterWeights()) {
      // TODO: some message here!!!!!!!!!!!
      // TODO:  do we need this??? initParameterWeights() never returns false...
      return false;
    }

    return true;
  }