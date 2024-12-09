inline void handle_strerror_r(bool& found, char*& result, char* strerror_t_ret)
    {
        result = strerror_t_ret; // actual message
        found = result != nullptr;
    }