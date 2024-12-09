void MakeHandle(uint32_t chunk_seq,
                size_t chunk_index,
                size_t event_index,
                TraceEventHandle* handle) {
  DCHECK(chunk_seq);
  DCHECK(chunk_index <= TraceBufferChunk::kMaxChunkIndex);
  DCHECK(event_index < TraceBufferChunk::kTraceBufferChunkSize);
  DCHECK(chunk_index <= std::numeric_limits<uint16_t>::max());
  handle->chunk_seq = chunk_seq;
  handle->chunk_index = static_cast<uint16_t>(chunk_index);
  handle->event_index = static_cast<uint16_t>(event_index);
}