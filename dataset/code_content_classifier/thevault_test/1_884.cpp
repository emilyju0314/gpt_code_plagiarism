void register_message_handler(
        char const* message_handler_type, char const* action, error_code& ec)
    {
        runtime_distributed* rtd = get_runtime_distributed_ptr();
        if (nullptr != rtd)
        {
            return rtd->register_message_handler(
                message_handler_type, action, ec);
        }

        // store the request for later
        detail::get_message_handler_registrations().push_back(
            hpx::make_tuple(message_handler_type, action));
    }