bool MLUTensorImpl::is_empty() {
  if (!cpu_storage_ || !storage_)
    return true;

  if (storage_.data() == nullptr && cpu_storage_.data() == nullptr)
    return true;

  return false;
}