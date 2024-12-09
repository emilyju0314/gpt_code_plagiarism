rsm_protocol::status
rsm::transferdonereq(std::string m, unsigned vid, int &)
{
  int ret = rsm_protocol::OK;
  ScopedLock ml(&rsm_mutex);
  // - Return BUSY if I am not insync, or if the slave is not synchronizing
  //   for the same view with me
  // - Remove the slave from the list of unsynchronized backups
  // - Wake up recovery thread if all backups are synchronized
  return ret;
}