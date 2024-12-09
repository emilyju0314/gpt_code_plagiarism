void AudioObject::ForEachDestLink(const LinkFunction& dest_task) {
  TRACE_DURATION("audio", "AudioObject::ForEachDestLink");
  std::lock_guard<std::mutex> links_lock(links_lock_);

  // Callers (generally AudioRenderers) should never be linked to sources.
  FX_DCHECK(source_links_.is_empty());

  for (auto& link : dest_links_) {
    dest_task(link);
  }
}