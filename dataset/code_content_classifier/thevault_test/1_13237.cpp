void MergeAllDependentConfigsFrom(const Target* from_target,
                                  UniqueVector<LabelConfigPair>* dest,
                                  UniqueVector<LabelConfigPair>* all_dest) {
  const UniqueVector<LabelConfigPair>& all =
      from_target->all_dependent_configs();
  for (size_t i = 0; i < all.size(); i++) {
    all_dest->push_back(all[i]);
    dest->push_back(all[i]);
  }
}