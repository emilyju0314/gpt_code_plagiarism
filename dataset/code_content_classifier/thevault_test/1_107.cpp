void StuckCheck::applyFilter(const std::vector<bool> & apply,
                             const Variables & filtervars,
                             std::vector<std::vector<bool>> & flagged) const {
  ObsAccessor obsAccessor = TrackCheckUtils::createObsAccessor(options_.stationIdVariable, obsdb_);
  const std::vector<size_t> validObsIds = obsAccessor.getValidObservationIds(apply);
  *obsGroupDateTimes_ = obsAccessor.getDateTimeVariableFromObsSpace(
        "MetaData", "datetime");
  // Create groups based on record number (assumed station ID) or category variable
  // (stationIdVariable) or otherwise assume observations all taken by the same station (1 group)
  RecursiveSplitter splitter = obsAccessor.splitObservationsIntoIndependentGroups(validObsIds);
  TrackCheckUtils::sortTracksChronologically(validObsIds, obsAccessor, splitter);
  std::vector<bool> isRejected(validObsIds.size(), false);
  std::vector<std::string> filterVariables = filtervars.toOopsVariables().variables();
  // Iterates through observations to see how long each variable is stuck on one observation
  for (std::string const& variable : filterVariables) {
    size_t stationNumber = 0;
    if (!obsdb_.has("ObsValue", variable)) {
      std::string errorMessage =
          "StuckCheck Error: ObsValue vector for " + variable + " not found.\n";
      throw std::invalid_argument(errorMessage);
    }
    const std::vector<float> variableValues = obsAccessor.getFloatVariableFromObsSpace(
          "ObsValue", variable);
    for (auto station : splitter.multiElementGroups()) {
      std::string stationId = std::to_string(stationNumber);
      std::vector<float> variableDataStation = collectStationVariableData(
            station.begin(), station.end(), validObsIds, variableValues);
      // the working variable's value associated with the prior observation
      float previousObservationValue;
      float currentObservationValue;
      size_t firstSameValueIndex = 0;  // the first observation in the current streak
      for (size_t observationIndex = 0; observationIndex < variableDataStation.size();
           observationIndex++) {
        currentObservationValue = variableDataStation.at(observationIndex);
        if (observationIndex == 0) {
          previousObservationValue = currentObservationValue;
        } else {
          if (currentObservationValue == previousObservationValue) {
            // If the last observation of the track is part of a streak, the full streak will need
            // to be checked at this point.
            if (observationIndex == variableDataStation.size() - 1) {
              StuckCheck::potentiallyRejectStreak(station.begin(),
                                                  station.end(),
                                                  validObsIds,
                                                  firstSameValueIndex,
                                                  observationIndex,
                                                  isRejected,
                                                  stationId);
            }
          } else {  // streak ended in the previous observation
            StuckCheck::potentiallyRejectStreak(station.begin(),
                                                station.end(),
                                                validObsIds,
                                                firstSameValueIndex,
                                                observationIndex - 1,
                                                isRejected,
                                                stationId);
            // start the streak with the current observation and reset the count to 1
            firstSameValueIndex = observationIndex;
            previousObservationValue = currentObservationValue;
          }
        }
      }
      stationNumber++;
    }
  }
  obsAccessor.flagRejectedObservations(isRejected, flagged);
}