rsm_protocol::status
rsm::transferreq(std::string src, viewstamp last, unsigned vid, 
rsm_protocol::transferres &r)
{
  ScopedLock ml(&rsm_mutex);
  int ret = rsm_protocol::OK;
  return ret;
}