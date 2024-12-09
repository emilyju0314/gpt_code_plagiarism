void
rsm::recovery()
{
  bool r = true;
  ScopedLock ml(&rsm_mutex);

  while (1) {
    while (!cfg->ismember(cfg->myaddr(), vid_commit)) {
      if (join(primary)) {
	tprintf("recovery: joined\n");
        commit_change_wo(cfg->vid());
      } else {
	VERIFY(pthread_mutex_unlock(&rsm_mutex)==0);
	sleep (30); // XXX make another node in cfg primary?
	VERIFY(pthread_mutex_lock(&rsm_mutex)==0);
      }
    }
    vid_insync = vid_commit;
    tprintf("recovery: sync vid_insync %d\n", vid_insync);
    if (primary == cfg->myaddr()) {
      r = sync_with_backups();
    } else {
      r = sync_with_primary();
    }
    tprintf("recovery: sync done\n");

    // If there was a commited viewchange during the synchronization, restart
    // the recovery
    if (vid_insync != vid_commit)
      continue;

    if (r) { 
      myvs.vid = vid_commit;
      myvs.seqno = 1;
      inviewchange = false;
    }
    tprintf("recovery: go to sleep %d %d\n", insync, inviewchange);
    pthread_cond_wait(&recovery_cond, &rsm_mutex);
  }
}