bool BaseFilter::MatchSite(const char* siteid) {
  return true;
  /*
  std::set<std::string>::iterator itr = site_ids_.find(siteid);
  if (default_enabled_) {
    return itr == site_ids_.end();
  } else {
    return itr != site_ids_.end();
  }
  */
}