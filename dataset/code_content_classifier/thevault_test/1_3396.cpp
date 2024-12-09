static lcos::barrier
create_barrier(std::size_t num_localities, char const* symname)
{
    lcos::barrier b = lcos::barrier::create(find_here(), num_localities);

    // register an unmanaged gid to avoid id-splitting during startup
    agas::register_name(launch::sync, symname, b.get_id().get_gid());
    return b;
}