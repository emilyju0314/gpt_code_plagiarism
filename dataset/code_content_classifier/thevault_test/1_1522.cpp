void ImportHrscSrcImage(ProcessImportPds &p, Pvl &label) {

  outCube = p.SetOutputCube("TO");
  p.StartProcess();

  Pvl otherLabels;
  TranslateHrscLabels(label, otherLabels);

  if (otherLabels.hasGroup("Instrument") &&
      (otherLabels.findGroup("Instrument").keywords() > 0)) {
    outCube->putGroup(otherLabels.findGroup("Instrument"));
  }

  if (otherLabels.hasGroup("BandBin") &&
      (otherLabels.findGroup("BandBin").keywords() > 0)) {
    outCube->putGroup(otherLabels.findGroup("BandBin"));
  }

  if (otherLabels.hasGroup("Archive") &&
      (otherLabels.findGroup("Archive").keywords() > 0)) {
    outCube->putGroup(otherLabels.findGroup("Archive"));
  }

  if (otherLabels.hasGroup("Kernels") &&
      (otherLabels.findGroup("Kernels").keywords() > 0)) {
    outCube->putGroup(otherLabels.findGroup("Kernels"));
  }

  p.EndProcess();
}