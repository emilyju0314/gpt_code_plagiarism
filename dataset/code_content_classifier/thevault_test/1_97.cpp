void TrackCheckShip::calculateTrackSegmentProperties(
    const std::vector<std::reference_wrapper<TrackObservation>> &trackObservations,
    CalculationMethod calculationMethod) const {
  if (trackObservations.size()) {
    if (calculationMethod == MAINLOOP)
      trackObservations[0].get().resetObservationCalculations();
    for (size_t obsIdx = 1; obsIdx < trackObservations.size(); obsIdx++) {
      TrackObservation &obs = trackObservations[obsIdx].get();
      TrackObservation &prevObs = trackObservations[obsIdx - 1].get();
      obs.calculateTwoObservationValues(prevObs, calculationMethod == FIRSTITERATION, options_);
      if (obsIdx > 1) {
        const TrackObservation &prevPrevObs = trackObservations[obsIdx - 2].get();
        prevObs.calculateThreeObservationValues(prevPrevObs, obs,
                                                calculationMethod == FIRSTITERATION, options_);
      }
      if (calculationMethod == FIRSTITERATION && (obsIdx == trackObservations.size() - 1)) {
        int potentialDenominator = trackObservations.size() - 1 -
            obs.getFullTrackStatistics()->numShort_ - obs.getFullTrackStatistics()->numFast_;
        (obs.getFullTrackStatistics()->meanSpeed_) = (obs.getFullTrackStatistics()->sumSpeed_) /
            std::max(1, potentialDenominator);
      }
    }
    if (options_.testingMode.value() && calculationMethod != MAINLOOP) {
      std::vector<TrackCheckShip::ObservationStatistics> obsStats;
      for (size_t obsIdx = 0; obsIdx < trackObservations.size(); ++obsIdx) {
        obsStats.push_back(trackObservations[obsIdx].get().getObservationStatistics());
      }
      auto trackStats = *(trackObservations[0].get().getFullTrackStatistics());
      if (calculationMethod == FIRSTITERATION)
        diagnostics_->storeInitialCalculationResults(std::make_pair(obsStats, trackStats));
    }
  }
}