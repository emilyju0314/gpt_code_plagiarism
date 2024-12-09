static lcos::barrier
find_barrier(char const* symname)
{
    naming::id_type barrier_id;
    for (std::size_t i = 0; i < HPX_MAX_NETWORK_RETRIES; ++i)
    {
        barrier_id = agas::resolve_name(launch::sync, symname);
        if (barrier_id != naming::invalid_id)
            break;

        boost::this_thread::sleep_for(
            boost::chrono::milliseconds(HPX_NETWORK_RETRIES_SLEEP));
    }
    if (HPX_UNLIKELY(!barrier_id))
    {
        HPX_THROW_EXCEPTION(network_error, "pre_main::find_barrier",
            std::string("couldn't find boot barrier ") + symname);
    }
    return lcos::barrier(barrier_id);
}