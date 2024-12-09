FsManager::~FsManager() {
  if (global_shutdown_.has_handler()) {
    event_.signal(0, FSHOST_SIGNAL_EXIT);
    auto deadline = zx::deadline_after(zx::sec(2));
    zx_signals_t pending;
    event_.wait_one(FSHOST_SIGNAL_EXIT_DONE, deadline, &pending);
  }
}