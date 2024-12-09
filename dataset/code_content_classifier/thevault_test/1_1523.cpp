void ImportHrscStereoImage(ProcessImportPds &p, Pvl &label) {

  UserInterface &ui = Application::GetUserInterface();

  lineInFile.clear();
  numLinesSkipped = 0;

  CubeAttributeOutput outAtt(ui.GetFileName("TO"));
  outCube = new Cube();

  outCube->setByteOrder(outAtt.byteOrder());
  outCube->setFormat(outAtt.fileFormat());
  outCube->setLabelsAttached(outAtt.labelAttachment() == AttachedLabel);

  TableField ephTimeField("EphemerisTime", TableField::Double);
  TableField expTimeField("ExposureTime", TableField::Double);
  TableField lineStartField("LineStart", TableField::Integer);

  TableRecord timesRecord;
  timesRecord += ephTimeField;
  timesRecord += expTimeField;
  timesRecord += lineStartField;

  Table timesTable("LineScanTimes", timesRecord);

  p.SetDataPrefixBytes((int)label.findObject("IMAGE")["LINE_PREFIX_BYTES"]);
  p.SaveDataPrefix();

  p.Progress()->SetText("Reading Prefix Data");
  p.StartProcess(IgnoreData);

  // Get the prefix data from the Process
  // The prefix data is always in LSB format, regardless of the overall file format
  EndianSwapper swapper("LSB");

  std::vector<double> ephemerisTimes;
  std::vector<double> exposureTimes;
  std::vector< std::vector<char *> > prefix = p.DataPrefix();

  for (int line = 0; line < p.Lines(); line++) {
    double ephTime = swapper.Double((double *)prefix[0][line]);
    double expTime = swapper.Float((float *)(prefix[0][line] + 8)) / 1000.0;

    if (line > 0) {
      /**
       * We know how many skipped lines with this equation. We take the
       * difference in the current line and the last line's time, which will
       * ideally be equal to the last line's exposure duration. We divide this by
       * the last line's exposure duration, and the result is the 1-based count of
       * how many exposures there were between the last line and the current line.
       * We subtract one in order to remove the known exposure, and the remaining should
       * be the 1-based count of how many lines were skipped. Add 0.5 to round up.
       */
      int skippedLines = (int)((ephTime - ephemerisTimes.back()) / exposureTimes.back() - 1.0 + 0.5);

      for (int i = 0; i < skippedLines; i++) {
        ephemerisTimes.push_back(ephemerisTimes.back() + exposureTimes.back());
        exposureTimes.push_back(exposureTimes.back());
        lineInFile.push_back(false);
      }
    }

    ephemerisTimes.push_back(ephTime);
    exposureTimes.push_back(expTime);
    lineInFile.push_back(true);
  }

  double lastExp = 0.0;
  for (unsigned int i = 0; i < ephemerisTimes.size(); i++) {
    if (lastExp != exposureTimes[i]) {
      lastExp = exposureTimes[i];
      timesRecord[0] = ephemerisTimes[i];
      timesRecord[1] = exposureTimes[i];
      timesRecord[2] = (int)i + 1;
      timesTable += timesRecord;
    }
  }

  outCube->setDimensions(p.Samples(), lineInFile.size(), p.Bands());

  p.Progress()->SetText("Importing");
  outCube->create(ui.GetFileName("TO"));
  p.StartProcess(WriteOutput);

  outCube->write(timesTable);

  // Translate the PDS labels into ISIS labels and add them to the cube
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

  outCube->close();
  delete outCube;
  outCube = NULL;
  lineInFile.clear();
}