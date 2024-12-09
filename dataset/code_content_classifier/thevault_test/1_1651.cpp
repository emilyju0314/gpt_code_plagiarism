bool BundleObservation::initParameterWeights() {

                                   // weights for
    double posWeight    = 0.0;     // position
    double velWeight    = 0.0;     // velocity
    double accWeight    = 0.0;     // acceleration
    double angWeight    = 0.0;     // angles
    double angVelWeight = 0.0;     // angular velocity
    double angAccWeight = 0.0;     // angular acceleration

    QList<double> aprioriPointingSigmas = m_solveSettings->aprioriPointingSigmas();
    QList<double> aprioriPositionSigmas = m_solveSettings->aprioriPositionSigmas();

    int nCamPosCoeffsSolved = 3  *m_solveSettings->numberCameraPositionCoefficientsSolved();

    int nCamAngleCoeffsSolved;
    if (m_solveSettings->solveTwist()) {
      nCamAngleCoeffsSolved = 3  *m_solveSettings->numberCameraAngleCoefficientsSolved();
    }
    else {
      nCamAngleCoeffsSolved = 2  *m_solveSettings->numberCameraAngleCoefficientsSolved();
    }

    if (aprioriPositionSigmas.size() >= 1 && aprioriPositionSigmas.at(0) > 0.0) {
      posWeight = aprioriPositionSigmas.at(0);
      posWeight = 1.0 / (posWeight  *posWeight * 1.0e-6);
    }
    if (aprioriPositionSigmas.size() >= 2 && aprioriPositionSigmas.at(1) > 0.0) {
      velWeight = aprioriPositionSigmas.at(1);
      velWeight = 1.0 / (velWeight  *velWeight * 1.0e-6);
    }
    if (aprioriPositionSigmas.size() >= 3 && aprioriPositionSigmas.at(2) > 0.0) {
      accWeight = aprioriPositionSigmas.at(2);
      accWeight = 1.0 / (accWeight  *accWeight * 1.0e-6);
    }

    if (aprioriPointingSigmas.size() >= 1 && aprioriPointingSigmas.at(0) > 0.0) {
      angWeight = aprioriPointingSigmas.at(0);
      angWeight = 1.0 / (angWeight  *angWeight * DEG2RAD * DEG2RAD);
    }
    if (aprioriPointingSigmas.size() >= 2 && aprioriPointingSigmas.at(1) > 0.0) {
      angVelWeight = aprioriPointingSigmas.at(1);
      angVelWeight = 1.0 / (angVelWeight * angVelWeight * DEG2RAD * DEG2RAD);
    }
    if (aprioriPointingSigmas.size() >= 3 && aprioriPointingSigmas.at(2) > 0.0) {
      angAccWeight = aprioriPointingSigmas.at(2);
      angAccWeight = 1.0 / (angAccWeight * angAccWeight * DEG2RAD * DEG2RAD);
    }

    int nSpkTerms = m_solveSettings->spkSolveDegree()+1;
    nSpkTerms = m_solveSettings->numberCameraPositionCoefficientsSolved();
    for ( int i = 0; i < nCamPosCoeffsSolved; i++) {
      if (i % nSpkTerms == 0) {
       m_aprioriSigmas[i] = aprioriPositionSigmas.at(0);
       m_weights[i] = posWeight;
      }
      if (i % nSpkTerms == 1) {
       m_aprioriSigmas[i] = aprioriPositionSigmas.at(1);
       m_weights[i] = velWeight;
      }
      if (i % nSpkTerms == 2) {
       m_aprioriSigmas[i] = aprioriPositionSigmas.at(2);
       m_weights[i] = accWeight;
      }
    }

    int nCkTerms = m_solveSettings->ckSolveDegree()+1;
    nCkTerms = m_solveSettings->numberCameraAngleCoefficientsSolved();
    for ( int i = 0; i < nCamAngleCoeffsSolved; i++) {
      if (i % nCkTerms == 0) {
        m_aprioriSigmas[nCamPosCoeffsSolved + i] = aprioriPointingSigmas.at(0);
        m_weights[nCamPosCoeffsSolved + i] = angWeight;
      }
      if (i % nCkTerms == 1) {
        m_aprioriSigmas[nCamPosCoeffsSolved + i] = aprioriPointingSigmas.at(1);
        m_weights[nCamPosCoeffsSolved + i] = angVelWeight;
      }
      if (i % nCkTerms == 2) {
        m_aprioriSigmas[nCamPosCoeffsSolved + i] = aprioriPointingSigmas.at(2);
        m_weights[nCamPosCoeffsSolved + i] = angAccWeight;
      }
    }

//    for ( int i = 0; i < (int)m_weights.size(); i++ )
//      std::cout << m_weights[i] << std::endl;

    return true;
  }