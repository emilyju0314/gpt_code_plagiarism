rObject
    Barrier::wait()
    {
      runner::Job& r = runner();
      value_type::iterator i =
        value_.insert(value_.end(), value_type::value_type(&r, rObject()));

      // No waiters are in the list, so mark it-self as the next waiter.
      if (rest_ == value_.end())
        rest_ = i;

      try
      {
        r.frozen_set(true);
        r.yield();

        // In no circumstances a signaled process could be marked as being a
        // waiter, this could only mean that the rest_ iterator has not been
        // correctly updated.
        aver(rest_ != i);

        // Regular wake up from a barrier wait.
        // Get the payload and remove us from the queue.
        rObject payload = i->second;
        value_.erase(i);
        return payload;
      }
      catch (...)
      {
        // In some rare cases when we receive a signal and an exception, the
        // payload is ignored and not forwarded to another waiter.  The
        // reason is to avoid getting his own signal back.  This differs
        // from the semaphore implementation.

        // Unfreeze the job.
        r.frozen_set(false);

        // Signal that we should no longer stay queued.  If the current
        // waiter is the next to be signaled, then skip it.  Remove it-self
        // from the list of waiters.
        if (rest_ == i)
          rest_++;

        // The erase operation should not go before the potential rest_
        // update, because this would invalidate the rest_ pointer.
        value_.erase(i);

        // Rethrow the exception received.
        throw;
      }
    }