void report_exception_and_continue(std::exception const& e)
    {
        pre_exception_handler();

        std::cerr << e.what() << std::endl;
    }