void ObjectPack::TransferBucket(
  const ObjectPack::BucketHandle handle,
  ObjectPack *other)
{
  MutexLockGuard mutex_guard(lock_);
  open_buckets_.erase(handle);
  other->open_buckets_.insert(handle);
}