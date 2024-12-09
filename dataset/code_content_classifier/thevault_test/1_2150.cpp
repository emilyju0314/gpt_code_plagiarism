void
config::paxos_commit(unsigned instance, std::string value)
{
  std::string m;
  std::vector<std::string> newmem;
  ScopedLock ml(&cfg_mutex);

  newmem = members(value);
  tprintf("config::paxos_commit: %d: %s\n", instance, 
	 print_members(newmem).c_str());

  for (unsigned i = 0; i < mems.size(); i++) {
    tprintf("config::paxos_commit: is %s still a member?\n", mems[i].c_str());
    if (!isamember(mems[i], newmem) && me != mems[i]) {
      tprintf("config::paxos_commit: delete %s\n", mems[i].c_str());
      mgr.delete_handle(mems[i]);
    }
  }

  mems = newmem;
  myvid = instance;
  if (vc) {
    unsigned vid = myvid;
    VERIFY(pthread_mutex_unlock(&cfg_mutex)==0);
    vc->commit_change(vid);
    VERIFY(pthread_mutex_lock(&cfg_mutex)==0);
  }
}