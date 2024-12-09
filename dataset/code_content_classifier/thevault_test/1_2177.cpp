rsm_client_protocol::status
rsm::client_members(int i, std::vector<std::string> &r)
{
  std::vector<std::string> m;
  ScopedLock ml(&rsm_mutex);
  m = cfg->get_view(vid_commit);
  m.push_back(primary);
  r = m;
  tprintf("rsm::client_members return %s m %s\n", print_members(m).c_str(),
	 primary.c_str());
  return rsm_client_protocol::OK;
}