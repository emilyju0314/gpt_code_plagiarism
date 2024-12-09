DescriptorError(const Calibration& calib, const std::vector<double>& p0,
                  const DescriptorFrame* frame, const std::vector<double>& w)
      : _radius(PatchRadiusFromLength(p0.size() / frame->numChannels())),
      _calib(calib), _p0(p0.data()), _frame(frame), _patch_weights(w.data())
  {
    // TODO should just pass the config to get the radius value
    assert( p0.size() == w.size() );
  }