void finalize()
{
  // The clock is only paused during tests.  Pausing may lead to infinite waits
  // during clean up, so we make sure the clock is running normally.
  Clock::resume();

  // This will terminate any existing processes created via `spawn()`,
  // like `gc`, `help`, `Logging()`, `Profiler()`, and `System()`.
  // NOTE: This will also stop the event loop.

  // TODO(arojas): The HTTP authentication logic in ProcessManager
  // does not handle the case where the process_manager is deleted
  // while authentication was in progress!!

  delete process_manager;
  process_manager = NULL;

  // The clock must be cleaned up after the `process_manager` as processes
  // may otherwise add timers after cleaning up.
  Clock::finalize();
}