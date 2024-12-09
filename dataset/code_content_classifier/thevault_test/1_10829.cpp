float Classify::ComputeNormMatch(CLASS_ID ClassId, const FEATURE_STRUCT &feature, bool DebugMatch) {
  if (ClassId >= NormProtos->NumProtos) {
    ClassId = NO_CLASS;
  }

  /* handle requests for classification as noise */
  if (ClassId == NO_CLASS) {
    /* kludge - clean up constants and make into control knobs later */
    float Match = (feature.Params[CharNormLength] * feature.Params[CharNormLength] * 500.0f +
                   feature.Params[CharNormRx] * feature.Params[CharNormRx] * 8000.0f +
                   feature.Params[CharNormRy] * feature.Params[CharNormRy] * 8000.0f);
    return (1.0f - NormEvidenceOf(Match));
  }

  float BestMatch = FLT_MAX;
  LIST Protos = NormProtos->Protos[ClassId];

  if (DebugMatch) {
    tprintf("\nChar norm for class %s\n", unicharset.id_to_unichar(ClassId));
  }

  int ProtoId = 0;
  iterate(Protos) {
    auto Proto = reinterpret_cast<PROTOTYPE *>(Protos->first_node());
    float Delta = feature.Params[CharNormY] - Proto->Mean[CharNormY];
    float Match = Delta * Delta * Proto->Weight.Elliptical[CharNormY];
    if (DebugMatch) {
      tprintf("YMiddle: Proto=%g, Delta=%g, Var=%g, Dist=%g\n", Proto->Mean[CharNormY], Delta,
              Proto->Weight.Elliptical[CharNormY], Match);
    }
    Delta = feature.Params[CharNormRx] - Proto->Mean[CharNormRx];
    Match += Delta * Delta * Proto->Weight.Elliptical[CharNormRx];
    if (DebugMatch) {
      tprintf("Height: Proto=%g, Delta=%g, Var=%g, Dist=%g\n", Proto->Mean[CharNormRx], Delta,
              Proto->Weight.Elliptical[CharNormRx], Match);
    }
    // Ry is width! See intfx.cpp.
    Delta = feature.Params[CharNormRy] - Proto->Mean[CharNormRy];
    if (DebugMatch) {
      tprintf("Width: Proto=%g, Delta=%g, Var=%g\n", Proto->Mean[CharNormRy], Delta,
              Proto->Weight.Elliptical[CharNormRy]);
    }
    Delta = Delta * Delta * Proto->Weight.Elliptical[CharNormRy];
    Delta *= kWidthErrorWeighting;
    Match += Delta;
    if (DebugMatch) {
      tprintf("Total Dist=%g, scaled=%g, sigmoid=%g, penalty=%g\n", Match,
              Match / classify_norm_adj_midpoint, NormEvidenceOf(Match),
              256 * (1 - NormEvidenceOf(Match)));
    }

    if (Match < BestMatch) {
      BestMatch = Match;
    }

    ProtoId++;
  }
  return 1.0 - NormEvidenceOf(BestMatch);
}