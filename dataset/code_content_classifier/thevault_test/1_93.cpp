void TrackCheckShip::applyFilter(const std::vector<bool> & apply,
                                 const Variables & filtervars,
                                 std::vector<std::vector<bool>> & flagged) const {
  ObsAccessor obsAccessor = TrackCheckUtils::createObsAccessor(options_.stationIdVariable, obsdb_);

  const std::vector<size_t> validObsIds
                                   = obsAccessor.getValidObservationIds(apply, *flags_, filtervars);

  RecursiveSplitter splitter = obsAccessor.splitObservationsIntoIndependentGroups(validObsIds);
  TrackCheckUtils::sortTracksChronologically(validObsIds, obsAccessor, splitter);

  TrackCheckUtils::ObsGroupLocationTimes obsLocTime =
      TrackCheckUtils::collectObservationsLocations(obsAccessor);

  std::vector<bool> isRejected(obsLocTime.latitudes.size(), false);
  size_t trackNumber = 0;
  for (auto track : splitter.multiElementGroups()) {
    trackNumber++;
    std::string stationId = std::to_string(trackNumber);
    std::vector<TrackObservation> trackObservations = collectTrackObservations(
          track.begin(), track.end(), validObsIds, obsLocTime);
    std::vector<std::reference_wrapper<TrackObservation>> trackObservationsReferences;
    trackObservationsReferences.reserve(trackObservations.size());
    std::transform(trackObservations.begin(), trackObservations.end(),
                   std::back_inserter(trackObservationsReferences),
                   [](TrackObservation &obs) {
      return std::ref<TrackObservation>(obs); });
    calculateTrackSegmentProperties(trackObservationsReferences,
                                    CalculationMethod::FIRSTITERATION);
    if (!trackObservationsReferences.empty() &&
        this->options_.core.earlyBreakCheck &&
        TrackCheckShip::earlyBreak(trackObservationsReferences, stationId)) {
      continue;
    }
      bool firstIterativeRemoval = true;
      while (trackObservationsReferences.size() >= 3) {
        // Initial loop: fastest (as determined by set of comparisons) observation removed
        // until all segments show slower speed than max threshold
        auto maxSpeedReferenceIterator = std::max_element(
              trackObservationsReferences.begin(), trackObservationsReferences.end(),
              [](TrackObservation a, TrackObservation b) {
            return a.getObservationStatistics().speed <
            b.getObservationStatistics().speed;});
        auto maxSpeedValue = maxSpeedReferenceIterator->get().getObservationStatistics().speed;
        if (maxSpeedValue <= (0.8 * options_.core.maxSpeed.value())) {
          break;
        } else if (maxSpeedValue < options_.core.maxSpeed.value()) {
          auto maxSpeedAngle = std::max(
                (maxSpeedReferenceIterator - 1)->get().getObservationStatistics().angle,
                maxSpeedReferenceIterator->get().getObservationStatistics().angle);
          if (maxSpeedAngle <= 90.0) {
            break;
          }
        }
        removeFaultyObservation(
              trackObservationsReferences, maxSpeedReferenceIterator, firstIterativeRemoval,
              stationId);
        firstIterativeRemoval = false;
        calculateTrackSegmentProperties(trackObservationsReferences, CalculationMethod::MAINLOOP);
      }
      auto rejectedCount = std::count_if(trackObservations.begin(), trackObservations.end(),
                    [](const TrackObservation& a) {return a.rejected();});
      if (rejectedCount >= options_.core.rejectionThreshold.value() * trackObservations.size()) {
        oops::Log::trace() << "CheckShipTrack: track " << stationId << " NumRej " <<
                              rejectedCount << " out of " << trackObservations.size() <<
                              " reports rejected. *** Reject whole track ***\n";
        for (TrackObservation &obs : trackObservations)
          obs.setRejected(true);
      }
      flagRejectedTrackObservations(track.begin(), track.end(),
                                    validObsIds, trackObservations, isRejected);
  }
  obsAccessor.flagRejectedObservations(isRejected, flagged);
}