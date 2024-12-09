void create_cout()
    {
        if (!agas::is_console())
        {
            HPX_THROW_EXCEPTION(service_unavailable,
                "hpx::iostreams::create_cout",
                "this function should be called on the console only");
        }
        detail::create_ostream(detail::cout_tag());
    }