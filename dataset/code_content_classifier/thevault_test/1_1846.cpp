void UnionOfSortedIntervals(absl::InlinedVector<ClosedInterval, 1>* intervals) {
  DCHECK(std::is_sorted(intervals->begin(), intervals->end()));
  int new_size = 0;
  for (const ClosedInterval& i : *intervals) {
    if (new_size > 0 && i.start <= CapAdd((*intervals)[new_size - 1].end, 1)) {
      (*intervals)[new_size - 1].end =
          std::max(i.end, (*intervals)[new_size - 1].end);
    } else {
      (*intervals)[new_size++] = i;
    }
  }
  intervals->resize(new_size);

  // This is important for InlinedVector in the case the result is a single
  // intervals.
  intervals->shrink_to_fit();
  DCHECK(IntervalsAreSortedAndNonAdjacent(*intervals));
}