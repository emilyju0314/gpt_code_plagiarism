static void RemountFinish() {
  if (!atomic_cas32(&reload_critical_section_, 0, 1))
    return;
  if (!atomic_read32(&drainout_mode_)) {
    atomic_cas32(&reload_critical_section_, 1, 0);
    return;
  }

  if (time(NULL) > drainout_deadline_) {
    LogCvmfs(kLogCvmfs, kLogDebug, "caches drained out, applying new catalog");

    // No new inserts into caches
    mount_point_->inode_cache()->Pause();
    mount_point_->path_cache()->Pause();
    mount_point_->md5path_cache()->Pause();
    mount_point_->inode_cache()->Drop();
    mount_point_->path_cache()->Drop();
    mount_point_->md5path_cache()->Drop();

    // Ensure that all Fuse callbacks left the catalog query code
    fence_remount_->Drain();
    catalog::LoadError retval = mount_point_->catalog_mgr()->Remount(false);
    if (mount_point_->inode_annotation()) {
      inode_generation_info_.inode_generation =
        mount_point_->inode_annotation()->GetGeneration();
    }
    mount_point_->ReEvaluateAuthz();
    fence_remount_->Open();

    mount_point_->inode_cache()->Resume();
    mount_point_->path_cache()->Resume();
    mount_point_->md5path_cache()->Resume();

    atomic_cas32(&drainout_mode_, 1, 0);
    if ((retval == catalog::kLoadFail) || (retval == catalog::kLoadNoSpace) ||
        mount_point_->catalog_mgr()->offline_mode())
    {
      LogCvmfs(kLogCvmfs, kLogDebug, "reload/finish failed, "
               "applying short term TTL");
      alarm(MountPoint::kShortTermTTL);
      catalogs_valid_until_ = time(NULL) + MountPoint::kShortTermTTL;
    } else {
      LogCvmfs(kLogCvmfs, kLogSyslog, "switched to catalog revision %d",
               mount_point_->catalog_mgr()->GetRevision());
      unsigned effective_ttl = mount_point_->GetEffectiveTtlSec();
      alarm(effective_ttl);
      catalogs_valid_until_ = time(NULL) + effective_ttl;
    }
  }

  atomic_cas32(&reload_critical_section_, 1, 0);
}