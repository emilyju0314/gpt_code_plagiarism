cpu_set_t unbind_to_core()
{
    cpu_set_t mask;
    mask = get_core_binding(); // record the current core binding

    bind_to_all();
    return mask;
}