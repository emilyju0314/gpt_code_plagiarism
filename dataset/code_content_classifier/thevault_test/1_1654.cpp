void BundleObservation::bundleOutputFetchData(QVector<double> &finalParameterValues,
                          int &nPositionCoefficients, int &nPointingCoefficients,
                          bool &useDefaultPosition,
                          bool &useDefaultPointing, bool &useDefaultTwist) {

    std::vector<double> coefX,coefY,coefZ,coefRA,coefDEC,coefTWI;
    nPositionCoefficients = m_solveSettings->numberCameraPositionCoefficientsSolved();
    nPointingCoefficients = m_solveSettings->numberCameraAngleCoefficientsSolved();

    // Indicate if we need to obtain default position or pointing values
    useDefaultPosition = false;
    useDefaultPointing = false;
    // Indicate if we need to use default values when not solving twist
    useDefaultTwist = !(m_solveSettings->solveTwist());

    // If we aren't solving for position, set the number of coefficients to 1 so we
    // can output the instrumentPosition's center coordinate values for X, Y, and Z
    if (nPositionCoefficients == 0) {
      nPositionCoefficients = 1;
      useDefaultPosition = true;
    }

    // If we arent' solving for pointing, set the number of coefficients to 1 so we
    // can output the instrumentPointing's center angles for RA, DEC, and TWI
    if (nPointingCoefficients == 0) {
      nPointingCoefficients = 1;
      useDefaultPointing = true;
    }

    coefX.resize(nPositionCoefficients);
    coefY.resize(nPositionCoefficients);
    coefZ.resize(nPositionCoefficients);
    coefRA.resize(nPointingCoefficients);
    coefDEC.resize(nPointingCoefficients);
    coefTWI.resize(nPointingCoefficients);

    if (m_instrumentPosition) {
      if (!useDefaultPosition) {
        m_instrumentPosition->GetPolynomial(coefX,coefY,coefZ);
      }
      // Use the position's center coordinate if not solving for spacecraft position
      else {
        const std::vector<double> centerCoord = m_instrumentPosition->GetCenterCoordinate();
        coefX[0] = centerCoord[0];
        coefY[0] = centerCoord[1];
        coefZ[0] = centerCoord[2];
      }
    }

    if (m_instrumentRotation) {
      if (!useDefaultPointing) {
        m_instrumentRotation->GetPolynomial(coefRA,coefDEC,coefTWI);
      }
      // Use the pointing's center angles if not solving for pointing (rotation)
      else {
        const std::vector<double> centerAngles = m_instrumentRotation->GetCenterAngles();
        coefRA[0] = centerAngles[0];
        coefDEC[0] = centerAngles[1];
        coefTWI[0] = centerAngles[2];
      }
    }

    // Combine all vectors into one
    if (nPositionCoefficients > 0) {
      for (int i=0; i < nPositionCoefficients; i++) {
        finalParameterValues.append(coefX[i]);
      }
      for (int i=0; i < nPositionCoefficients; i++) {
        finalParameterValues.append(coefY[i]);
      }
      for (int i=0; i < nPositionCoefficients; i++) {
        finalParameterValues.append(coefZ[i]);
      }
    }
    if (nPointingCoefficients > 0) {
      for (int i=0; i < nPointingCoefficients; i++) {
        finalParameterValues.append(coefRA[i]);
      }
      for (int i=0; i < nPointingCoefficients; i++) {
        finalParameterValues.append(coefDEC[i]);
      }
      for (int i=0; i < nPointingCoefficients; i++) {
        finalParameterValues.append(coefTWI[i]);
      }
    }

  }