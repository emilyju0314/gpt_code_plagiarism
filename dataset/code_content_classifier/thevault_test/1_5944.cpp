void
  UGenericCallback::setAsync(libport::ThreadPool::rTaskLock l)
  {
    synchronous_ = false;
    taskLock = l;
  }