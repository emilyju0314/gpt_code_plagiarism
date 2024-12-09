bool BundleObservation::initializeExteriorOrientation() {

    if (m_solveSettings->instrumentPositionSolveOption() !=
        BundleObservationSolveSettings::NoPositionFactors) {

      double positionBaseTime = 0.0;
      double positiontimeScale = 0.0;
      std::vector<double> posPoly1, posPoly2, posPoly3;

      for (int i = 0; i < size(); i++) {
        BundleImageQsp image = at(i);
        SpicePosition *spicePosition = image->camera()->instrumentPosition();

        if (i > 0) {
          spicePosition->SetPolynomialDegree(m_solveSettings->spkSolveDegree());
          spicePosition->SetOverrideBaseTime(positionBaseTime, positiontimeScale);
          spicePosition->SetPolynomial(posPoly1, posPoly2, posPoly3,
                                       m_solveSettings->positionInterpolationType());
        }
        else {
          // first, set the degree of the spk polynomial to be fit for a priori values
          spicePosition->SetPolynomialDegree(m_solveSettings->spkDegree());

          // now, set what kind of interpolation to use (SPICE, memcache, hermitecache, polynomial
          // function, or polynomial function over constant hermite spline)
          // TODO: verify - I think this actually performs the a priori fit
          spicePosition->SetPolynomial(m_solveSettings->positionInterpolationType());

          // finally, set the degree of the spk polynomial actually used in the bundle adjustment
          spicePosition->SetPolynomialDegree(m_solveSettings->spkSolveDegree());

          if (m_instrumentPosition) { // ??? TODO: why is this different from rotation code below???
            positionBaseTime = m_instrumentPosition->GetBaseTime();
            positiontimeScale = m_instrumentPosition->GetTimeScale();
            m_instrumentPosition->GetPolynomial(posPoly1, posPoly2, posPoly3);
          }
        }
      }
    }

    if (m_solveSettings->instrumentPointingSolveOption() !=
        BundleObservationSolveSettings::NoPointingFactors) {

      double rotationBaseTime = 0.0;
      double rotationtimeScale = 0.0;
      std::vector<double> anglePoly1, anglePoly2, anglePoly3;

      for (int i = 0; i < size(); i++) {
        BundleImageQsp image = at(i);
        SpiceRotation *spicerotation = image->camera()->instrumentRotation();

        if (i > 0) {
          spicerotation->SetPolynomialDegree(m_solveSettings->ckSolveDegree());
          spicerotation->SetOverrideBaseTime(rotationBaseTime, rotationtimeScale);
          spicerotation->SetPolynomial(anglePoly1, anglePoly2, anglePoly3,
                                       m_solveSettings->pointingInterpolationType());
        }
        else {
          // first, set the degree of the spk polynomial to be fit for a priori values
          spicerotation->SetPolynomialDegree(m_solveSettings->ckDegree());

          // now, set what kind of interpolation to use (SPICE, memcache, hermitecache, polynomial
          // function, or polynomial function over constant hermite spline)
          // TODO: verify - I think this actually performs the a priori fit
          spicerotation->SetPolynomial(m_solveSettings->pointingInterpolationType());

          // finally, set the degree of the spk polynomial actually used in the bundle adjustment
          spicerotation->SetPolynomialDegree(m_solveSettings->ckSolveDegree());

          rotationBaseTime = spicerotation->GetBaseTime();
          rotationtimeScale = spicerotation->GetTimeScale();
          spicerotation->GetPolynomial(anglePoly1, anglePoly2, anglePoly3);
        }
      }
    }

    return true;
  }