TEMP_CONFIG_STRUCT::TEMP_CONFIG_STRUCT(int maxProtoId, int fontinfoId) {
  int NumProtos = maxProtoId + 1;

  Protos = NewBitVector(NumProtos);

  NumTimesSeen = 1;
  MaxProtoId = maxProtoId;
  ProtoVectorSize = WordsInVectorOfSize(NumProtos);
  zero_all_bits(Protos, ProtoVectorSize);
  FontinfoId = fontinfoId;
}