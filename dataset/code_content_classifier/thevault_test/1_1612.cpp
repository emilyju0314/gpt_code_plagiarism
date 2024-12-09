bool CheckFramelets(QString progress, Cube &theCube) {
  bool foundValidFramelet = false;
  LineManager mgr(theCube);
  Progress prog;
  prog.SetText(progress);
  prog.SetMaximumSteps(theCube.lineCount());
  prog.CheckStatus();

  vector<double> frameletAvgs;
  // We need to store off the framelet information, because if no good
  //   framelets were found then no data should be added to the
  //   global variable for framelets, just files.
  vector< pair<int, double> > excludedFrameletsTmp;
  Statistics frameletStats;

  for(int line = 1; line <= theCube.lineCount(); line++) {
    if((line - 1) % numFrameLines == 0) {
      frameletStats.Reset();
    }

    mgr.SetLine(line);
    theCube.read(mgr);
    frameletStats.AddData(mgr.DoubleBuffer(), mgr.size());

    if((line - 1) % numFrameLines == numFrameLines - 1) {
      if(IsSpecial(frameletStats.StandardDeviation()) ||
          frameletStats.StandardDeviation() > maxStdev) {
        excludedFrameletsTmp.push_back(
          pair<int, double>((line - 1) / numFrameLines, frameletStats.StandardDeviation())
        );
      }
      else {
        foundValidFramelet = true;
      }

      frameletAvgs.push_back(frameletStats.Average());
    }

    prog.CheckStatus();
  }

  inputFrameletAverages.push_back(frameletAvgs);

  if(foundValidFramelet) {
    for(unsigned int i = 0; i < excludedFrameletsTmp.size(); i++) {
      excludedFramelets.insert(pair< pair<int, int>, double>(
                                 pair<int, int>(currImage, excludedFrameletsTmp[i].first),
                                 excludedFrameletsTmp[i].second
                               )
                              );
    }

  }

  return foundValidFramelet;
}