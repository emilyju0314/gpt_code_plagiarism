void ColPartitionSet::AddToColumnSetsIfUnique(PartSetVector *column_sets,
                                              const WidthCallback &cb) {
  bool debug = TabFind::WithinTestRegion(2, bounding_box_.left(),
                                         bounding_box_.bottom());
  if (debug) {
    tprintf("Considering new column candidate:\n");
    Print();
  }
  if (!LegalColumnCandidate()) {
    if (debug) {
      tprintf("Not a legal column candidate:\n");
      Print();
    }
    delete this;
    return;
  }
  for (unsigned i = 0; i < column_sets->size(); ++i) {
    ColPartitionSet *columns = column_sets->at(i);
    // In ordering the column set candidates, good_coverage_ is king,
    // followed by good_column_count_ and then bad_coverage_.
    bool better = good_coverage_ > columns->good_coverage_;
    if (good_coverage_ == columns->good_coverage_) {
      better = good_column_count_ > columns->good_column_count_;
      if (good_column_count_ == columns->good_column_count_) {
        better = bad_coverage_ > columns->bad_coverage_;
      }
    }
    if (better) {
      // The new one is better so add it.
      if (debug) {
        tprintf("Good one\n");
      }
      column_sets->insert(column_sets->begin() + i, this);
      return;
    }
    if (columns->CompatibleColumns(false, this, cb)) {
      if (debug) {
        tprintf("Duplicate\n");
      }
      delete this;
      return; // It is not unique.
    }
  }
  if (debug) {
    tprintf("Added to end\n");
  }
  column_sets->push_back(this);
}