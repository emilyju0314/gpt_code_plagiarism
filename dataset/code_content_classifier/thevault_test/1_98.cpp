void TrackCheckShip::TrackObservation::adjustTwoObservationStatistics
(const TrackCheckShipParameters &options) const {
  util::Duration hour{"PT1H"};
  if (getObservationStatistics().timeDifference < hour) {
    getFullTrackStatistics()->numShort_++;
  } else if (getObservationStatistics().speed >= options.core.maxSpeed) {
    getFullTrackStatistics()->numFast_++;
  } else {
    getFullTrackStatistics()->sumSpeed_ += getObservationStatistics().speed;
  }
}