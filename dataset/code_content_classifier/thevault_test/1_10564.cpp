MICROFEATURES ConvertToMicroFeatures(MFOUTLINE Outline, MICROFEATURES MicroFeatures) {
  MFOUTLINE Current;
  MFOUTLINE Last;
  MFOUTLINE First;

  if (DegenerateOutline(Outline)) {
    return (MicroFeatures);
  }

  First = NextExtremity(Outline);
  Last = First;
  do {
    Current = NextExtremity(Last);
    if (!PointAt(Current)->Hidden) {
      auto NewFeature = ExtractMicroFeature(Last, Current);
      MicroFeatures.push_front(NewFeature);
    }
    Last = Current;
  } while (Last != First);

  return MicroFeatures;
}