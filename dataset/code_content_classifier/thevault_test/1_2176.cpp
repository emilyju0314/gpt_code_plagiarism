rsm_protocol::status
rsm::joinreq(std::string m, viewstamp last, rsm_protocol::joinres &r)
{
  int ret = rsm_protocol::OK;

  ScopedLock ml(&rsm_mutex);
  tprintf("joinreq: src %s last (%d,%d) mylast (%d,%d)\n", m.c_str(), 
	 last.vid, last.seqno, last_myvs.vid, last_myvs.seqno);
  if (cfg->ismember(m, vid_commit)) {
    tprintf("joinreq: is still a member\n");
    r.log = cfg->dump();
  } else if (cfg->myaddr() != primary) {
    tprintf("joinreq: busy\n");
    ret = rsm_protocol::BUSY;
  } else {
    // We cache vid_commit to avoid adding m to a view which already contains 
    // m due to race condition
    unsigned vid_cache = vid_commit;
    VERIFY (pthread_mutex_unlock(&rsm_mutex) == 0);
    bool succ = cfg->add(m, vid_cache);
    VERIFY (pthread_mutex_lock(&rsm_mutex) == 0);
    if (cfg->ismember(m, cfg->vid())) {
      r.log = cfg->dump();
      tprintf("joinreq: ret %d log %s\n:", ret, r.log.c_str());
    } else {
      tprintf("joinreq: failed; proposer couldn't add %d\n", succ);
      ret = rsm_protocol::BUSY;
    }
  }
  return ret;
}