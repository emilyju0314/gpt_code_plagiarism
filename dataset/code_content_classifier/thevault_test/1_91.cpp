double TrackCheckShip::speedEstimate(
    const TrackCheckShip::TrackObservation &obs1,
    const TrackCheckShip::TrackObservation &obs2,
    const TrackCheckShipParameters& options) {
  util::Duration temporalDistance = abs(obs1.getTime() -
                                        obs2.getTime());
  util::Duration tempRes = options.core.temporalResolution;
  auto dist = distance(obs1, obs2);
  auto spatialRes = options.core.spatialResolution;
  double speedEst = 0.0;
  if (dist > spatialRes) {
    speedEst = (dist - 0.5 * spatialRes) /
        std::max(temporalDistance.toSeconds(),
                 (tempRes.toSeconds()));
    speedEst *= 1000.0;  // convert units from km/s to m/s
  }
  return speedEst;
}