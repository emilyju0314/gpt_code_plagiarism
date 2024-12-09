int BundleObservation::numberPointingParameters() {
    int angleCoefficients = m_solveSettings->numberCameraAngleCoefficientsSolved();

    if (m_solveSettings->solveTwist()) {
      return 3.0 * angleCoefficients;
    }
    return 2.0 * angleCoefficients;
  }