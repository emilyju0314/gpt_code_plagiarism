inline bool SuspendThreads() noexcept {
    if (!RequestThreadsSuspension()) {
        return false;
    }
    WaitForThreadsSuspension();
    return true;
}