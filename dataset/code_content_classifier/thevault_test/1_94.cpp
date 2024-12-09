bool TrackCheckShip::earlyBreak(const std::vector<std::reference_wrapper<TrackObservation>>
                                &trackObs, const std::string trackId) const {
  bool breakResult = false;
  const auto& trackStats = *(trackObs[0].get().getFullTrackStatistics());
  // if at least half of the track segments have a time difference of less than an hour
  // (if non-buoy), are faster than a configured maximum speed, or exhibit at least a 90
  // degree bend
  if ((2 * ((options_.inputCategory.value() != SurfaceObservationSubtype::BUOY &&
             options_.inputCategory.value() != SurfaceObservationSubtype::BUOYPROF)
            * trackStats.numShort_ + trackStats.numFast_) + trackStats.numBends_)
      >= (trackObs.size() - 1)) {
    oops::Log::trace() << "ShipTrackCheck: " << trackId << "\n" <<
                          "Time difference < 1 hour: " << trackStats.numShort_ << "\n" <<
                          "Fast: " << trackStats.numFast_ << "\n" <<
                          "Bends: " << trackStats.numBends_ << "\n" <<
                          "Total observations: " << trackObs.size() << "\n" <<
                          "Track was not checked." << std::endl;

    breakResult = true;
  }
  if (options_.testingMode)
    diagnostics_->storeEarlyBreakResult(breakResult);
  return breakResult;
}