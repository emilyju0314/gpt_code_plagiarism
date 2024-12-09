QString BundleObservation::bundleOutputCSV(bool errorPropagation) {

    QVector<double> finalParameterValues;
    int nPositionCoefficients, nPointingCoefficients;
    bool useDefaultPosition, useDefaultPointing,useDefaultTwist;

    bundleOutputFetchData(finalParameterValues,
                          nPositionCoefficients,nPointingCoefficients,
                          useDefaultPosition,useDefaultPointing,useDefaultTwist);

    int nPositionParameters = 3 * nPositionCoefficients;
    int nPointingParameters = 3 * nPointingCoefficients;
    int nParameters = nPositionParameters + nPointingParameters;

    QString finalqStr = "";

    // Set up default values when we are using default position
    QString sigma = "N/A";
    QString adjustedSigma = "N/A";
    double correction = 0.0;

    // Position parameters
    for (int i = 0; i < nPositionParameters; i++) {
      if (!useDefaultPosition) {
        correction = m_corrections(i);
        adjustedSigma = QString::number(m_adjustedSigmas[i], 'f', 8);
        sigma = ( IsSpecial(m_aprioriSigmas[i]) ? "FREE" : toString(m_aprioriSigmas[i], 8) );
      }
      // Provide default values for position if not solving position
      else {
        correction = 0.0;
        adjustedSigma = "N/A";
        sigma = "N/A";
      }

      finalqStr += toString(finalParameterValues[i] - correction) + ",";
      finalqStr += toString(correction) + ",";
      finalqStr += toString(finalParameterValues[i]) + ",";
      finalqStr += sigma + ",";
      if (errorPropagation) {
        finalqStr += adjustedSigma + ",";
      }
      else {
        finalqStr += "N/A,";
      }

    }

    // If not solving position, we need to offset access to correction and sigma members by -3
    // (X,Y,Z) since m_corrections and m_*sigmas are populated according to which parameters are
    // solved
    int offset = 0;
    if (useDefaultPosition) {
      offset = 3;
    }
    // pointing parameters
    for (int i = nPositionParameters; i < nParameters; i++) {
      if (!useDefaultPointing) {
        // Use default values if solving camera but not solving for TWIST to prevent bad indexing
        // into m_corrections and m_*sigmas
        if ( (i >= nParameters - nPointingCoefficients) && useDefaultTwist) {
          correction = 0.0;
          adjustedSigma = "N/A";
          sigma = "N/A";
        }
        else {
          correction = m_corrections(i - offset);
          adjustedSigma = QString::number(m_adjustedSigmas(i-offset) * RAD2DEG, 'f', 8);
          sigma = ( IsSpecial(m_aprioriSigmas[i-offset]) ? "FREE" :
              toString(m_aprioriSigmas[i-offset], 8) );
        }
      }
      // Provide default values for pointing if not solving pointing
      else {
        correction = 0.0;
        adjustedSigma = "N/A";
        sigma = "N/A";
      }

      finalqStr += toString(finalParameterValues[i]*RAD2DEG - correction * RAD2DEG) + ",";
      finalqStr += toString(correction * RAD2DEG) + ",";
      finalqStr += toString(finalParameterValues[i]*RAD2DEG) + ",";
      finalqStr += sigma + ",";
      if (errorPropagation) {
        finalqStr += adjustedSigma + ",";
      }
      else {
        finalqStr += "N/A,";
      }

    }

    return finalqStr;
  }