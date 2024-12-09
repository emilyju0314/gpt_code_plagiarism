void RubberBandTool::enable(RubberBandMode mode, bool showIndicatorColors) {
    RubberBandMode oldMode = p_bandingMode;
    p_bandingMode = mode;
    p_indicatorColors = showIndicatorColors;
    //Took this out because it was reseting and not letting us plot single points.
    //p_pointTolerance = 0;
    p_allClicks = false;
    p_drawActiveOnly = false;
    reset();
    activate(true);

    if(oldMode != mode) {
      emit modeChanged();
    }
  }