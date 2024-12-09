BundleObservation::BundleObservation(BundleImageQsp image, QString observationNumber,
                                       QString instrumentId, BundleTargetBodyQsp bundleTargetBody) {
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

    m_observationNumber = observationNumber;
    m_instrumentId = instrumentId;

    m_bundleTargetBody = bundleTargetBody;

    if (image) {
      append(image);
      m_serialNumbers.append(image->serialNumber());
      m_imageNames.append(image->fileName());
      m_cubeSerialNumberToBundleImageMap.insert(image->serialNumber(), image);

      // set the observations spice position and rotation objects from the primary image in the
      // observation (this is, by design at the moment, the first image added to the observation)
      // if the image, camera, or instrument position/orientation is null, then set to null
      m_instrumentPosition = (image->camera() ?
                               (image->camera()->instrumentPosition() ?
                                 image->camera()->instrumentPosition() : NULL)
                               : NULL);
      m_instrumentRotation = (image->camera() ?
                               (image->camera()->instrumentRotation() ?
                                  image->camera()->instrumentRotation() : NULL)
                               : NULL);

      // set the observations target body spice rotation object from the primary image in the
      // observation (this is, by design at the moment, the first image added to the observation)
      // if the image, camera, or instrument position/orientation is null, then set to null
//      m_bodyRotation = (image->camera() ?
//                           (image->camera()->bodyRotation() ?
//                             image->camera()->bodyRotation() : NULL)
//                           : NULL);
    }
  }