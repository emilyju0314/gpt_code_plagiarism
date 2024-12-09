ProcWatch::ProcWatch(NVIDIA &nv, bool enabled, unsigned sleep_ms) noexcept:
        nv(nv), // Nvidia DVC setting
        dirty(false),   // signals watcher that rules need to be reapplied
        active(enabled),        // do stuff?
        terminate(false),       // tells watcher thread that it should shut down
        sleep_ms(sleep_ms)      // sleep timer for watcher thread
{
        watcher = std::thread(&ProcWatch::update, this);
}