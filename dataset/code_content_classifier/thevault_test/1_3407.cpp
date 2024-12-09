void big_boot_barrier::trigger()
{
    if (service_mode_bootstrap == service_type)
    {
        util::unique_function_nonser<void()>* p;

        while (thunks.pop(p))
        {
            try
            {
                (*p)();
            }
            catch(...)
            {
                delete p;
                throw;
            }
            delete p;
        }
    }
}