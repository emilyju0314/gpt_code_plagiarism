synchronized (processes_mutex) {
    if (processes.count(pid.id) > 0) {
      process = processes[pid.id];
      CHECK(process->state != ProcessBase::TERMINATED);

      // Check and see if a gate already exists.
      if (gates.find(process) == gates.end()) {
        gates[process] = new Gate();
      }

      gate = gates[process];
      old = gate->approach();

      // Check if it is runnable in order to donate this thread.
      if (process->state == ProcessBase::BOTTOM ||
          process->state == ProcessBase::READY) {
        synchronized (runq_mutex) {
          list<ProcessBase*>::iterator it =
            find(runq.begin(), runq.end(), process);
          if (it != runq.end()) {
            // Found it! Remove it from the run queue since we'll be
            // donating our thread and also increment 'running' before
            // leaving this 'runq' protected critical section so that
            // everyone that is waiting for the processes to settle
            // continue to wait (otherwise they could see nothing in
            // 'runq' and 'running' equal to 0 between when we exit
            // this critical section and increment 'running').
            runq.erase(it);
            running.fetch_add(1);
          } else {
            // Another thread has resumed the process ...
            process = NULL;
          }
        }
      } else {
        // Process is not runnable, so no need to donate ...
        process = NULL;
      }
    }
  }