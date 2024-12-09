bool AudioObject::ForAnyDestLink(const LinkBoolFunction& dest_task) {
  TRACE_DURATION("audio", "AudioObject::ForAnyDestLink");
  std::lock_guard<std::mutex> links_lock(links_lock_);

  for (auto& link : dest_links_) {
    if (dest_task(link)) {
      return true;  // This link satisfied the need; we are done.
    }
    // Else, continue inquiring with the remaining links.
  }
  return false;  // No link satisfied the need.
}