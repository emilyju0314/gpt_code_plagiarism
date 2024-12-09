void AudioObject::ForEachSourceLink(const LinkFunction& source_task) {
  TRACE_DURATION("audio", "AudioObject::ForEachSourceLink");
  std::lock_guard<std::mutex> links_lock(links_lock_);

  // Callers (generally AudioCapturers) should never be linked to destinations.
  FX_DCHECK(dest_links_.is_empty());

  for (auto& link : source_links_) {
    source_task(link);
  }
}