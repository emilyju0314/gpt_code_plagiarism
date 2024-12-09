int ensure_no_runtime_is_up()
        {
            // make sure the runtime system is not active yet
            if (get_runtime_ptr() != nullptr)
            {
#if defined(HPX_HAVE_DYNAMIC_HPX_MAIN) &&                                      \
    (defined(__linux) || defined(__linux__) || defined(linux) ||               \
        defined(__APPLE__))
                // make sure the runtime system is not initialized
                // after its activation from int main()
                if (hpx_start::include_libhpx_wrap)
                {
                    std::cerr
                        << "hpx is already initialized from main.\n"
                           "Note: Delete hpx_main.hpp to initialize hpx system "
                           "using hpx::init. Exiting...\n";
                    return -1;
                }
#endif
                std::cerr << "hpx::init: can't initialize runtime system "
                             "more than once! Exiting...\n";
                return -1;
            }
            return 0;
        }