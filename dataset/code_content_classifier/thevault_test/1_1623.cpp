ClipperWacFcCamera::ClipperWacFcCamera(Cube &cube) : FramingCamera(cube) {
    m_spacecraftNameLong = "Europa Clipper";
    m_spacecraftNameShort = "Clipper";

    m_instrumentNameLong  = "Europa Imaging System Framing Wide Angle Camera";
    m_instrumentNameShort = "EIS-FWAC";

    NaifStatus::CheckErrors();

    SetFocalLength(); 
    SetPixelPitch();

    // Set up detector map, focal plane map, and distortion map
    new CameraDetectorMap(this);
    new CameraFocalPlaneMap(this, naifIkCode());
    new CameraDistortionMap(this);
    
    // Setup the ground and sky map
    new CameraGroundMap(this);
    new CameraSkyMap(this);

    Pvl &lab = *cube.label();
    PvlGroup &inst = lab.findGroup("Instrument", Pvl::Traverse);
    QString startTime = inst["StartTime"];
    iTime etStart(startTime);

    // double exposureDuration = (double)inst["ExposureDuration"] / 1000.0;
    // pair<iTime, iTime> startStop = ShutterOpenCloseTimes(et, exposureDuration);

     setTime(etStart.Et()); // Set the time explicitly for now to prevent segfault

    // Internalize all the NAIF SPICE information into memory.
    LoadCache();
    NaifStatus::CheckErrors();
  }