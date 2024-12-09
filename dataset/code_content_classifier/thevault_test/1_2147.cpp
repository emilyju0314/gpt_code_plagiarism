void HowToDynamicSepsis()
{
  // Create the engine and have it run in it's own thread
  // This call will block while the engine stabilizes
  DynamicSepsis sepThread("./DynamicSepsis.csv");
  // When it comes back, the engine will be running, waiting for your input

  int action;
  double sev;
  std::string location;
  bool active = true;
  double rate;
  double concentration;
  std::string out;

  do {
    sepThread.GetLogger()->Info("Enter Integer for Action to Perform : [1]Status, [2]Initiate Sepsis, [3]IVFluids, [4] Antibiotic Admin, [5], Norepinephrine Admin, [6]Quit");
    std::cin >> action;
    switch (action) {
    case 1:
      sepThread.Status();
      break;
    case 2:
      sepThread.GetLogger()->Info("Type a location, then hit ENTER: ");
      std::cin >> location;
      sepThread.GetLogger()->Info("Type a severity (0-1), then hit ENTER: ");
      std::cin >> sev;
      if (sev < 0 || sev > 1.0) {
        out = "Severity out of bounds, default to 0.5";
        sev = 0.5;
      } else if (sev <= ZERO_APPROX)
        out = "Sepsis action disabled in  " + location;
      else
        out = "Sepsis in " + location + " with severity = " + std::to_string(sev);
      sepThread.GetLogger()->Info(out);
      sepThread.SetSepsis(location, sev);
      break;
    case 3:
      sepThread.GetLogger()->Info("Enter IV Fluids Rate in mL/min (bag volume is 500 mL), then hit ENTER : ");
      std::cin >> rate;
      sepThread.GetLogger()->Info(std::stringstream() << rate);
      sepThread.SetIVFluidsFlow_mL_Per_min(rate);
      break;
    case 4:
      sepThread.GetLogger()->Info("Administering antibiotics (4.5 g over 4 hrs");
      sepThread.SetAntibiotic();
      break;
    case 5:
      sepThread.GetLogger()->Info("Enter a concentration in ug/mL (will be delivered at 1 mL/min), then hit ENTER : ");
      std::cin >> concentration;
      sepThread.GetLogger()->Info(std::stringstream() << concentration);
      sepThread.SetNorepinephrine(concentration);
      break;
    case 6:
      active = false;
    }
  } while (active);
}