int AddProtoToClass(CLASS_TYPE Class) {
  if (Class->NumProtos >= Class->MaxNumProtos) {
    /* add protos in PROTO_INCREMENT chunks at a time */
    int NewNumProtos =
        (((Class->MaxNumProtos + PROTO_INCREMENT) / PROTO_INCREMENT) * PROTO_INCREMENT);

    Class->Prototypes.resize(NewNumProtos);

    Class->MaxNumProtos = NewNumProtos;
    ASSERT_HOST(NewNumProtos <= MAX_NUM_PROTOS);
  }
  int NewProto = Class->NumProtos++;
  ASSERT_HOST(Class->NumProtos <= MAX_NUM_PROTOS);
  return (NewProto);
}