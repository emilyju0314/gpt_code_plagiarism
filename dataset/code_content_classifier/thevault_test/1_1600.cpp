void camstats(UserInterface &ui, Pvl *log) {
    Process p;

    CubeAttributeInput cai;
    Cube *icube = p.SetInputCube(ui.GetFileName("FROM"), cai, ReadWrite);
    camstats(icube, ui, log);

    p.EndProcess();
  }