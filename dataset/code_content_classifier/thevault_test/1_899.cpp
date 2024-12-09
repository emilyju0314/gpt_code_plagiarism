void future_data_base<traits::detail::future_data_void>::run_on_completed(
        completed_callback_type&& on_completed) noexcept
    {
        try
        {
            hpx::util::annotate_function annotate(on_completed);
            on_completed();
        }
        catch (...)
        {
            // If the completion handler throws an exception, there's nothing
            // we can do, report the exception and terminate.
            if (run_on_completed_error_handler)
            {
                run_on_completed_error_handler(std::current_exception());
            }
            else
            {
                std::terminate();
            }
        }
    }