synchronized (runq_mutex) {
      if (!runq.empty()) {
        done = false;
        continue;
      }

      if (running.load() > 0) {
        done = false;
        continue;
      }

      if (!Clock::settled()) {
        done = false;
        continue;
      }
    }