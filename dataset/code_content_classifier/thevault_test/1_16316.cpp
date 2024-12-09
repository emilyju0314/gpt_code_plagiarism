bool ObjectPack::CommitBucket(
  const shash::Any &id,
  const ObjectPack::BucketHandle handle)
{
  handle->id = id;

  MutexLockGuard mutex_guard(lock_);
  if (buckets_.size() >= kMaxObjects)
    return false;
  if (size_ + handle->size > limit_)
    return false;
  open_buckets_.erase(handle);
  buckets_.push_back(handle);
  size_ += handle->size;
  return true;
}