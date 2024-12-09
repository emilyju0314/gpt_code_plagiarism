u_int TimestampSctpAgent::ControlChunkReservation()
{
  DBG_I(ControlChunkReservation);
  DBG_PL(ControlChunkReservation, "returning %d"), 
    sizeof(SctpTimestampChunk_S) DBG_PR;
  DBG_X(ControlChunkReservation);
  return sizeof(SctpTimestampChunk_S);
}