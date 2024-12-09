bool unregister_lock_globally(void const* lock)
    {
        using detail::register_locks_globally;

        if (register_locks_globally::lock_detection_enabled_ &&
            nullptr != threads::get_self_ptr())
        {
            register_locks_globally::held_locks_map& held_locks =
                register_locks_globally::get_lock_map();

            std::unique_lock<register_locks_globally::mutex_type> l(
                register_locks_globally::get_mutex());

            register_locks_globally::held_locks_map::iterator it =
                held_locks.find(lock);
            if (it == held_locks.end())
                return false;    // this lock is not registered

            held_locks.erase(lock);
        }
        return true;
    }