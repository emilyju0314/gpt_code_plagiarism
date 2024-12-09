std::function<bool(size_t, size_t)> Gaussian_Thinning::makeObservationComparator(
    const std::vector<size_t> &validObsIds,
    const std::vector<float> &distancesToBinCenter,
    const ObsAccessor &obsAccessor) const
{
  if (options_.priorityVariable.value() == boost::none) {
    return [&distancesToBinCenter](size_t validObsIndexA, size_t validObsIndexB) {
      return distancesToBinCenter[validObsIndexA] < distancesToBinCenter[validObsIndexB];
    };
  }

  const ufo::Variable priorityVariable = options_.priorityVariable.value().get();

  std::vector<int> priorities = obsAccessor.getIntVariableFromObsSpace(
        priorityVariable.group(), priorityVariable.variable());

  // TODO(wsmigaj): In C++14, use move capture for 'priorities'.
  return [priorities, &validObsIds, &distancesToBinCenter]
         (size_t validObsIndexA, size_t validObsIndexB) {
      // Prefer observations with large priorities and small distances
      return std::make_pair(-priorities[validObsIds[validObsIndexA]],
                            distancesToBinCenter[validObsIndexA]) <
             std::make_pair(-priorities[validObsIds[validObsIndexB]],
                            distancesToBinCenter[validObsIndexB]);
    };
}