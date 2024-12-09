bool BundleObservation::applyParameterCorrections(LinearAlgebra::Vector corrections) {

    int index = 0;

    try {
      int nCameraAngleCoefficients = m_solveSettings->numberCameraAngleCoefficientsSolved();
      int nCameraPositionCoefficients = m_solveSettings->numberCameraPositionCoefficientsSolved();

      BundleObservationSolveSettings::InstrumentPositionSolveOption positionOption
          = m_solveSettings->instrumentPositionSolveOption();
      if (positionOption != BundleObservationSolveSettings::NoPositionFactors) {

        if (!m_instrumentPosition) {
          QString msg = "Instrument position is NULL, but position solve option is ";
          msg.append(BundleObservationSolveSettings::instrumentPositionSolveOptionToString(
                     positionOption));
          throw IException(IException::Unknown, msg, _FILEINFO_);
        }

        std::vector<double> coefX(nCameraPositionCoefficients);
        std::vector<double> coefY(nCameraPositionCoefficients);
        std::vector<double> coefZ(nCameraPositionCoefficients);

        m_instrumentPosition->GetPolynomial(coefX, coefY, coefZ);

        // update X coordinate coefficient(s) and sum parameter correction
        for (int i = 0; i < nCameraPositionCoefficients; i++) {
          coefX[i] += corrections(index);
          index++;
        }

        // update Y coordinate coefficient(s) and sum parameter correction
        for (int i = 0; i < nCameraPositionCoefficients; i++) {
          coefY[i] += corrections(index);
          index++;
        }

        // update Z coordinate coefficient(s) and sum parameter correction
        for (int i = 0; i < nCameraPositionCoefficients; i++) {
          coefZ[i] += corrections(index);
          index++;
        }

        // apply updates to all images in observation
        for (int i = 0; i < size(); i++) {
          BundleImageQsp image = at(i);
          SpicePosition *spiceposition = image->camera()->instrumentPosition();
          spiceposition->SetPolynomial(coefX, coefY, coefZ,
                                       m_solveSettings->positionInterpolationType());
        }
      }

      BundleObservationSolveSettings::InstrumentPointingSolveOption pointingOption
          = m_solveSettings->instrumentPointingSolveOption();
      if (pointingOption != BundleObservationSolveSettings::NoPointingFactors) {

        if (!m_instrumentRotation) {
          QString msg = "Instrument rotation is NULL, but pointing solve option is ";
          msg.append(BundleObservationSolveSettings::instrumentPointingSolveOptionToString(
                     pointingOption));
          throw IException(IException::Unknown, msg, _FILEINFO_);
        }

        std::vector<double> coefRA(nCameraPositionCoefficients);
        std::vector<double> coefDEC(nCameraPositionCoefficients);
        std::vector<double> coefTWI(nCameraPositionCoefficients);

        m_instrumentRotation->GetPolynomial(coefRA, coefDEC, coefTWI);

        // update RA coefficient(s)
        for (int i = 0; i < nCameraAngleCoefficients; i++) {
          coefRA[i] += corrections(index);
          index++;
        }

        // update DEC coefficient(s)
        for (int i = 0; i < nCameraAngleCoefficients; i++) {
          coefDEC[i] += corrections(index);
          index++;
        }

        if (m_solveSettings->solveTwist()) {
          // update TWIST coefficient(s)
          for (int i = 0; i < nCameraAngleCoefficients; i++) {
            coefTWI[i] += corrections(index);
            index++;
          }
        }

        // apply updates to all images in observation
        for (int i = 0; i < size(); i++) {
          BundleImageQsp image = at(i);
          SpiceRotation *spiceRotation = image->camera()->instrumentRotation();
          spiceRotation->SetPolynomial(coefRA, coefDEC, coefTWI,
                                       m_solveSettings->pointingInterpolationType());
        }
      }

      // update corrections
      m_corrections += corrections;

    }
    catch (IException &e) {
      QString msg = "Unable to apply parameter corrections to BundleObservation.";
      throw IException(e, IException::Unknown, msg, _FILEINFO_);
    }
    return true;
  }