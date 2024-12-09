catalog::LoadError RemountStart() {
  catalog::LoadError retval = mount_point_->catalog_mgr()->Remount(true);
  if (retval == catalog::kLoadNew) {
    LogCvmfs(kLogCvmfs, kLogDebug,
             "new catalog revision available, draining out meta-data caches");
    unsigned safety_margin = kReloadSafetyMargin/1000;
    if (safety_margin == 0)
      safety_margin = 1;
    drainout_deadline_ =
      time(NULL) +
      static_cast<int>(mount_point_->kcache_timeout_sec()) +
      safety_margin;
    atomic_cas32(&drainout_mode_, 0, 1);
  }
  return retval;
}