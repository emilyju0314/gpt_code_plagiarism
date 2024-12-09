int fluid_note_container_insert(void* cont, fluid_note_id_t id)
{
    try
    {
        std::pair<note_container_t::iterator, bool> res = static_cast<note_container_t*>(cont)->insert(id);
        // res.second tells us whether the element was inserted
        // by inverting it, we know whether it contained the element previously
        return !res.second;
    }
    catch(...)
    {
        return FLUID_FAILED;
    }
}