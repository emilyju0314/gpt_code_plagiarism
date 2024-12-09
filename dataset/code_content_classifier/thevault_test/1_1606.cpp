void cnetstats(UserInterface &ui, Pvl *log) {
    ControlNet innet(ui.GetFileName("CNET"));
    QString inlist(ui.GetFileName("FROMLIST"));

    cnetstats(innet, inlist, ui, log);
  }