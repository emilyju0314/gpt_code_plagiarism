void MergeDirectDependentConfigsFrom(const Target* from_target,
                                     UniqueVector<LabelConfigPair>* dest) {
  const UniqueVector<LabelConfigPair>& direct =
      from_target->direct_dependent_configs();
  for (size_t i = 0; i < direct.size(); i++)
    dest->push_back(direct[i]);
}