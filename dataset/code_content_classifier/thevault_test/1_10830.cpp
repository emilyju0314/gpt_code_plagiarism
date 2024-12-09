NORM_PROTOS *Classify::ReadNormProtos(TFile *fp) {
  char unichar[2 * UNICHAR_LEN + 1];
  UNICHAR_ID unichar_id;
  LIST Protos;
  int NumProtos;

  /* allocate and initialization data structure */
  auto NormProtos = new NORM_PROTOS(unicharset.size());

  /* read file header and save in data structure */
  NormProtos->NumParams = ReadSampleSize(fp);
  NormProtos->ParamDesc = ReadParamDesc(fp, NormProtos->NumParams);

  /* read protos for each class into a separate list */
  const int kMaxLineSize = 100;
  char line[kMaxLineSize];
  while (fp->FGets(line, kMaxLineSize) != nullptr) {
    std::istringstream stream(line);
    stream.imbue(std::locale::classic());
    stream >> unichar >> NumProtos;
    if (stream.fail()) {
      continue;
    }
    if (unicharset.contains_unichar(unichar)) {
      unichar_id = unicharset.unichar_to_id(unichar);
      Protos = NormProtos->Protos[unichar_id];
      for (int i = 0; i < NumProtos; i++) {
        Protos = push_last(Protos, ReadPrototype(fp, NormProtos->NumParams));
      }
      NormProtos->Protos[unichar_id] = Protos;
    } else {
      tprintf("Error: unichar %s in normproto file is not in unichar set.\n", unichar);
      for (int i = 0; i < NumProtos; i++) {
        FreePrototype(ReadPrototype(fp, NormProtos->NumParams));
      }
    }
  }
  return NormProtos;
}