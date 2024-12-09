static void RemountCheck() {
  if (atomic_read32(&maintenance_mode_) == 1)
    return;
  RemountFinish();

  if (atomic_cas32(&catalogs_expired_, 1, 0)) {
    LogCvmfs(kLogCvmfs, kLogDebug, "catalog TTL expired, reload");
    catalog::LoadError retval = RemountStart();
    if ((retval == catalog::kLoadFail) || (retval == catalog::kLoadNoSpace)) {
      LogCvmfs(kLogCvmfs, kLogDebug, "reload failed (%s), "
                                     "applying short term TTL",
               catalog::Code2Ascii(retval));
      alarm(MountPoint::kShortTermTTL);
      catalogs_valid_until_ = time(NULL) + MountPoint::kShortTermTTL;
    } else if (retval == catalog::kLoadUp2Date) {
      LogCvmfs(kLogCvmfs, kLogDebug,
               "catalog up to date, applying effective TTL");
      unsigned effective_ttl = mount_point_->GetEffectiveTtlSec();
      alarm(effective_ttl);
      catalogs_valid_until_ = time(NULL) + effective_ttl;
    }
  }
}