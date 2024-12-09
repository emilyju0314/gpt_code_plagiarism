void ConvertToPicoFeatures2(MFOUTLINE Outline, FEATURE_SET FeatureSet) {
  MFOUTLINE Next;
  MFOUTLINE First;
  MFOUTLINE Current;

  if (DegenerateOutline(Outline)) {
    return;
  }

  First = Outline;
  Current = First;
  Next = NextPointAfter(Current);
  do {
    /* note that an edge is hidden if the ending point of the edge is
   marked as hidden.  This situation happens because the order of
   the outlines is reversed when they are converted from the old
   format.  In the old format, a hidden edge is marked by the
   starting point for that edge. */
    if (!(PointAt(Next)->Hidden)) {
      ConvertSegmentToPicoFeat(&(PointAt(Current)->Point), &(PointAt(Next)->Point), FeatureSet);
    }

    Current = Next;
    Next = NextPointAfter(Current);
  } while (Current != First);

}