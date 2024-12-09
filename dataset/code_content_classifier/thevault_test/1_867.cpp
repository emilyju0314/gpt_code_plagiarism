bool runtime_configuration::enable_minimal_deadlock_detection() const
    {
#ifdef HPX_HAVE_THREAD_MINIMAL_DEADLOCK_DETECTION
        if (util::section const* sec = get_section("hpx"); nullptr != sec)
        {
#ifdef HPX_DEBUG
            return hpx::util::get_entry_as<int>(
                       *sec, "minimal_deadlock_detection", 1) != 0;
#else
            return hpx::util::get_entry_as<int>(
                       *sec, "minimal_deadlock_detection", 0) != 0;
#endif
        }

#ifdef HPX_DEBUG
        return true;
#else
        return false;
#endif

#else
        return false;
#endif
    }