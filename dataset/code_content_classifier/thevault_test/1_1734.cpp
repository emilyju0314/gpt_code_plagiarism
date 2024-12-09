void ApplicationInfo::AutomaticUpdate() {
  memory_used_ = 0;
  disk_used_ = 0;

  int64 entry_size = sizeof(UrlFprint) + sizeof(VisitingRecord);
  std::map<std::string, SiteInfo>::iterator itr = site_infos_.begin();
  for (; itr != site_infos_.end(); ++itr) {
    SiteInfo& info = itr->second;
    info.set_memory_used(entry_size * info.url_in_memory());
    info.set_disk_used(entry_size * (info.url_in_database() + info.url_in_tempfile()));

    memory_used_ += info.memory_used();
    disk_used_ += info.disk_used();
  }
}