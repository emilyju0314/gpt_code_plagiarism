void CreateTemporaryData(Buffer &in) {
  /**
   * Line scan cameras process by frame columns.
   */
  if(cameraType == LineScan) {
    // The statistics of every column of data need to be known
    //   before we can write to the temp file. Gather stats for this
    //   column.
    Statistics inputColStats;

    for(int i = 0; i < in.size(); i++) {
      inputColStats.AddData(in[i]);

      // We'll also need the stats for the entire frame in order to
      //   normalize and in order to decide whether or not we want
      //   to toss out the frame
      inputFrameStats.AddData(in[i]);
    }

    // Store off the column stats
    outputTmpAverages[in.Sample()-1] = inputColStats.Average();
    outputTmpCounts[in.Sample()-1] = inputColStats.ValidPixels();

    // Test if this is the last column and we've got all of our stats
    if(in.Sample() == numOutputSamples) {
      // Decide if we want this data
      if(IsSpecial(inputFrameStats.StandardDeviation()) ||
          inputFrameStats.StandardDeviation() > maxStdev) {
        // We don't want this data...
        //   CreateNullData is a helper method for this case that
        //   nulls out the stats
        CreateNullData();

        // Record the exclusion
        PvlGroup currExclusion("ExcludedLines");
        currExclusion += PvlKeyword("FrameStartLine", toString(in.Line()));
        currExclusion += PvlKeyword("ValidPixels", toString(inputFrameStats.ValidPixels()));

        if(!IsSpecial(inputFrameStats.StandardDeviation()))
          currExclusion += PvlKeyword("StandardDeviation", toString(inputFrameStats.StandardDeviation()));
        else
          currExclusion += PvlKeyword("StandardDeviation", "N/A");

        excludedDetails[excludedDetails.size()-1].addGroup(currExclusion);
      }

      // Let's write our data... CreateNullData took care of nulls for us
      // Band 1 is our normalized average
      oLineMgr->SetLine(oLineMgr->Line(), 1);
      for(int i = 0; i < (int)outputTmpAverages.size(); i++) {
        if(!IsSpecial(outputTmpAverages[i])) {
          (*oLineMgr)[i] = outputTmpAverages[i] / inputFrameStats.Average();
        }
        else {
          (*oLineMgr)[i] = Isis::Null;
        }
      }

      ocube->write(*oLineMgr);
      oLineMgr->SetLine(oLineMgr->Line(), 2);

      // band 2 is our valid dn counts
      for(int i = 0; i < (int)outputTmpCounts.size(); i++) {
        (*oLineMgr)[i] = outputTmpCounts[i];
        numInputDns[i] += (int)(outputTmpCounts[i] + 0.5);
      }

      ocube->write(*oLineMgr);
      (*oLineMgr) ++;

      inputFrameStats.Reset();
    }
  }
  else if(cameraType == Framing || cameraType == PushFrame) {
    // Framing cameras and push frames are treated identically;
    //   the framelet size for a framelet in the framing camera
    //   is the entire image!
    int framelet = (in.Line() - 1) / numFrameLines;
    double stdev;
    bool excluded = Excluded(currImage, framelet, stdev);

    if(excluded && ((in.Line() - 1) % numFrameLines == 0)) {
      PvlGroup currExclusion("ExcludedFramelet");
      currExclusion += PvlKeyword("FrameletStartLine", toString(in.Line()));
      currExclusion += PvlKeyword("FrameletNumber", toString((in.Line() - 1) / numFrameLines));

      if(!IsSpecial(stdev)) {
        currExclusion += PvlKeyword("StandardDeviation",
                                    toString(stdev));
      }
      else {
        currExclusion += PvlKeyword("StandardDeviation",
                                    "N/A");
      }

      excludedDetails[excludedDetails.size()-1].addGroup(currExclusion);
    }

    // Since this is a line by line iterative process, we need to get the current
    //   data in the temp file
    oLineMgr->SetLine(((in.Line() - 1) % numFrameLines) + 1, 1);

    if(!excluded || !cubeInitialized) {
      ocube->read(*oLineMgr);
    }

    if(!cubeInitialized) {
      for(int i = 0; i < oLineMgr->size(); i++) {
        (*oLineMgr)[i] = Isis::Null;
      }
    }

    vector<bool> isValidData;

    if(!excluded || !cubeInitialized) {
      isValidData.resize(in.size());

      for(int samp = 0; samp < in.size(); samp++) {
        if(IsSpecial((*oLineMgr)[samp]) && !IsSpecial(in[samp])) {
          (*oLineMgr)[samp] = 0.0;
        }

        if(!IsSpecial(in[samp])) {
          isValidData[samp] = true;
          (*oLineMgr)[samp] += in[samp] / inputFrameletAverages[currImage][framelet];
        }
        else {
          isValidData[samp] = false;
        }
      }
    }

    if(!excluded || !cubeInitialized) {
      ocube->write(*oLineMgr);
    }

    oLineMgr->SetLine(oLineMgr->Line(), 2);

    if(!excluded || !cubeInitialized) {
      ocube->read(*oLineMgr);
    }

    if(!cubeInitialized) {
      for(int i = 0; i < oLineMgr->size(); i++) {
        (*oLineMgr)[i] = Isis::Null;
      }

      if(ocube->lineCount() == oLineMgr->Line())
        cubeInitialized = true;
    }

    if(!excluded || !cubeInitialized) {
      for(int i = 0; i < (int)isValidData.size(); i++) {
        if(IsSpecial((*oLineMgr)[i])) {
          (*oLineMgr)[i] = 0.0;
        }

        if(isValidData[i]) {
          (*oLineMgr)[i] ++;
        }
      }
    }

    if(!excluded || !cubeInitialized) {
      ocube->write(*oLineMgr);
    }
  }
}