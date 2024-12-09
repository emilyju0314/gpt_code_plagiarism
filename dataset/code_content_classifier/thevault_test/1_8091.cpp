void Mu2eG4TrackingAction::beginRun(const PhysicalVolumeHelper* physVolHelper,
                                PhysicsProcessInfo* processInfo,
                                CLHEP::Hep3Vector const& mu2eOrigin ){
    _physVolHelper = physVolHelper;
    _processInfo = processInfo;
    _mu2eOrigin    =  mu2eOrigin;
  }