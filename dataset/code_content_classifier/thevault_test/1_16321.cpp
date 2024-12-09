bool PosixCacheManager::AcquireQuotaManager(QuotaManager *quota_mgr) {
  if (quota_mgr == NULL)
    return false;
  delete quota_mgr_;
  quota_mgr_ = quota_mgr;
  return true;
}