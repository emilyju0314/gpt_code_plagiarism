void TrackCheckShip::TrackObservation::calculateThreeObservationValues(
    const TrackObservation& prevObs, const TrackObservation& nextObs,
    bool firstIteration, const TrackCheckShipParameters &options) {
  this->setDistanceAveraged(TrackCheckShip::distance(prevObs, nextObs));
  this->setSpeedAveraged(speedEstimate(prevObs, nextObs, options));
  if (std::min(this->observationStatistics_.distance,
               nextObs.observationStatistics_.distance) >
      options.core.spatialResolution) {
    this->observationStatistics_.angle = angle(prevObs, *this, nextObs);
  }
  if (firstIteration) {
    adjustThreeObservationStatistics();
  }
}