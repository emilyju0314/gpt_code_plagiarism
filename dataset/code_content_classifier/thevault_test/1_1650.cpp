void BundleObservation::initializeBodyRotation() {
    std::vector<Angle> raCoefs = m_bundleTargetBody->poleRaCoefs();
    std::vector<Angle> decCoefs = m_bundleTargetBody->poleDecCoefs();
    std::vector<Angle> pmCoefs = m_bundleTargetBody->pmCoefs();

    for (int i = 0; i < size(); i++) {
      BundleImageQsp image = at(i);
      image->camera()->bodyRotation()->setPckPolynomial(raCoefs, decCoefs, pmCoefs);
    }
  }