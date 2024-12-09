void future_data_base<traits::detail::future_data_void>::set_on_completed(
        completed_callback_type data_sink)
    {
        if (!data_sink)
            return;

        if (is_ready())
        {
            // invoke the callback (continuation) function right away
            handle_on_completed(std::move(data_sink));
        }
        else
        {
            std::unique_lock<mutex_type> l(mtx_);
            if (is_ready())
            {
                l.unlock();

                // invoke the callback (continuation) function
                handle_on_completed(std::move(data_sink));
            }
            else
            {
                on_completed_.push_back(std::move(data_sink));
            }
        }
    }