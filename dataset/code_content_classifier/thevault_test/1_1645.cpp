BundleObservation::BundleObservation() {
    m_serialNumbers.clear();
    m_imageNames.clear();
    m_parameterNamesList.clear();
    m_observationNumber = "";
    m_instrumentId = "";
    m_instrumentRotation = NULL;
    m_instrumentPosition = NULL;
    m_index = 0;
    m_weights.clear();
    m_corrections.clear();
//    m_solution.clear();
    m_aprioriSigmas.clear();
    m_adjustedSigmas.clear();
  }