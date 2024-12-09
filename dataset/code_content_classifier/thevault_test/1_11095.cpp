static void WriteNormProtos(const char *Directory, LIST LabeledProtoList,
                            const FEATURE_DESC_STRUCT *feature_desc) {
  FILE *File;
  LABELEDLIST LabeledProto;
  int N;

  std::string Filename = "";
  if (Directory != nullptr && Directory[0] != '\0') {
    Filename += Directory;
    Filename += "/";
  }
  Filename += "normproto";
  printf("\nWriting %s ...", Filename.c_str());
  File = fopen(Filename.c_str(), "wb");
  ASSERT_HOST(File);
  fprintf(File, "%0d\n", feature_desc->NumParams);
  WriteParamDesc(File, feature_desc->NumParams, feature_desc->ParamDesc);
  iterate(LabeledProtoList) {
    LabeledProto = reinterpret_cast<LABELEDLIST>(LabeledProtoList->first_node());
    N = NumberOfProtos(LabeledProto->List, true, false);
    if (N < 1) {
      printf(
          "\nError! Not enough protos for %s: %d protos"
          " (%d significant protos"
          ", %d insignificant protos)\n",
          LabeledProto->Label.c_str(), N, NumberOfProtos(LabeledProto->List, true, false),
          NumberOfProtos(LabeledProto->List, false, true));
      exit(1);
    }
    fprintf(File, "\n%s %d\n", LabeledProto->Label.c_str(), N);
    WriteProtos(File, feature_desc->NumParams, LabeledProto->List, true, false);
  }
  fclose(File);

}