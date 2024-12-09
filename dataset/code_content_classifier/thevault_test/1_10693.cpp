bool ResultIterator::IsAtFinalElement(PageIteratorLevel level, PageIteratorLevel element) const {
  if (Empty(element)) {
    return true; // Already at the end!
  }
  // The result is true if we step forward by element and find we are
  // at the the end of the page or at beginning of *all* levels in:
  // [level, element).
  // When there is more than one level difference between element and level,
  // we could for instance move forward one symbol and still be at the first
  // word on a line, so we also have to be at the first symbol in a word.
  ResultIterator next(*this);
  next.Next(element);
  if (next.Empty(element)) {
    return true; // Reached the end of the page.
  }
  while (element > level) {
    element = static_cast<PageIteratorLevel>(element - 1);
    if (!next.IsAtBeginningOf(element)) {
      return false;
    }
  }
  return true;
}