void TrackCheckShip::TrackObservation::calculateTwoObservationValues(
    TrackObservation& prevObs, bool firstIteration,
    const TrackCheckShipParameters &options) {
  this->setDistance(TrackCheckShip::distance(prevObs, *this));
  (this->observationStatistics_.distance > options.core.spatialResolution) ?
        this->setSpeed(TrackCheckShip::speedEstimate(*this, prevObs, options)) :
        this->setSpeed(0.0);
  this->setTimeDifference(getTime() - prevObs.getTime());
  if (firstIteration) {
    adjustTwoObservationStatistics(options);
  }
}