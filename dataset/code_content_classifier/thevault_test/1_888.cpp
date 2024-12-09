bool is_networking_enabled()
    {
        runtime* rt = get_runtime_ptr();
        if (nullptr != rt)
        {
            return rt->is_networking_enabled();
        }
        return true;    // be on the safe side, enable networking
    }