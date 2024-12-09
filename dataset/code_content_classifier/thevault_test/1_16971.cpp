void TraceLog::ConvertTraceEventsToTraceFormat(
    std::unique_ptr<TraceBuffer> logged_events,
    const OutputCallback& flush_output_callback,
    const ArgumentFilterPredicate& argument_filter_predicate) {
  if (flush_output_callback.is_null())
    return;

  HEAP_PROFILER_SCOPED_IGNORE;
  // The callback need to be called at least once even if there is no events
  // to let the caller know the completion of flush.
  scoped_refptr<RefCountedString> json_events_str_ptr = new RefCountedString();
  const size_t kReserveCapacity = kTraceEventBufferSizeInBytes * 5 / 4;
  json_events_str_ptr->data().reserve(kReserveCapacity);
  while (const TraceBufferChunk* chunk = logged_events->NextChunk()) {
    for (size_t j = 0; j < chunk->size(); ++j) {
      size_t size = json_events_str_ptr->size();
      if (size > kTraceEventBufferSizeInBytes) {
        flush_output_callback.Run(json_events_str_ptr, true);
        json_events_str_ptr = new RefCountedString();
        json_events_str_ptr->data().reserve(kReserveCapacity);
      } else if (size) {
        json_events_str_ptr->data().append(",\n");
      }
      chunk->GetEventAt(j)->AppendAsJSON(&(json_events_str_ptr->data()),
                                         argument_filter_predicate);
    }
  }
  flush_output_callback.Run(json_events_str_ptr, false);
}