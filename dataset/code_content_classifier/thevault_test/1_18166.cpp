void StarFieldGUI::updateFieldState(bool reset) {
    if (!m_freePointMassArray) {
      m_freePointMassArray = new QScatterDataArray;
      generateFPMInitialStates();
    }

    if (!m_starArray) {
      m_starArray = new QScatterDataArray;
    }

    int fpmArraySize = pow(m_freePointMassCube + 1, 3);
    if (fpmArraySize != m_freePointMassArray->size() || reset) {
      m_freePointMassArray->resize(fpmArraySize);
      generateFPMInitialStates();
    }

    if (c_stars.size() != m_starArray->size()) {
      m_starArray->resize(c_stars.size());
    }

    {  // we wish to limit the scope of fpm and sdi
      QScatterDataItem* sdi = &m_freePointMassArray->first();
      auto fpm = c_fpms.begin();

      for (float i = 0; i <= m_freePointMassCube; i++) {
        for (float j = 0; j <= m_freePointMassCube; j++) {
          for (float k = 0; k <= m_freePointMassCube; k++, ++sdi, ++fpm) {
            // position this arrow
            sdi->setPosition(
                QVector3D(fpm->p.vec[0], fpm->p.vec[1], fpm->p.vec[2]));

            // rotate this arrow to point in the direction of the vector
            Vec basisArrow{0.0, 1.0, 0.0};
            auto basisVelocity = fpm->v.unit_vector();
            QQuaternion rt = rotateToVector(basisArrow, basisVelocity);
            sdi->setRotation(rt);
          }
        }
      }
    }

    QScatterDataItem* pstar =
        (!m_starArray->empty()) ? &m_starArray->first() : nullptr;

    for (auto star : c_stars) {
      assert(pstar != nullptr);
      pstar->setPosition(
          QVector3D(star.position[0], star.position[1], star.position[2]));
      ++pstar;
    }

    if (m_graph->selectedSeries() == m_freePointMass) m_graph->clearSelection();

    m_freePointMass->dataProxy()->resetArray(m_freePointMassArray);
    m_stars->dataProxy()->resetArray(m_starArray);
  }