void iTime::LoadLeapSecondKernel() {
    // Inorder to improve the speed of iTime comparisons, the leapsecond
    // kernel is loaded only once and left open.
    if(p_lpInitialized) return;

    // Get the leap second kernel file open
    Isis::PvlGroup &dataDir = Isis::Preference::Preferences().findGroup("DataDirectory");
    QString baseDir = dataDir["Base"];
    baseDir += "/kernels/lsk/";
    FileName leapSecond(baseDir + "naif????.tls");

    NaifStatus::CheckErrors();
    QString leapSecondName(leapSecond.highestVersion().expanded());
    furnsh_c(leapSecondName.toLatin1().data());
    NaifStatus::CheckErrors();

    p_lpInitialized = true;
  }