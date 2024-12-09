void save_ghosts(const vector<ghost_demon> &ghosts, bool force, bool use_store)
{
    // n.b. this is not called in the normal course of events for wizmode
    // chars, so for debugging anything to do with deaths in wizmode, you will
    // need to edit a conditional at the end of ouch.cc:ouch.
    _ghost_dprf("Trying to save ghosts.");
    if (ghosts.empty())
    {
        _ghost_dprf("Could not find any ghosts for this level to save.");
        return;
    }

    if (!force && !ghost_demon::ghost_eligible())
    {
        _ghost_dprf("No eligible ghosts.");
        return;
    }

    vector<ghost_demon> leftovers;
    if (use_store)
        leftovers = _update_permastore(ghosts);
    else
        leftovers = ghosts;
    if (leftovers.size() == 0)
        return;

    if (_list_bones().size() >= static_cast<size_t>(GHOST_LIMIT))
    {
        _ghost_dprf("Too many ghosts for this level already!");
        return;
    }

    string g_file_name = "";
    FILE* ghost_file = _make_bones_file(&g_file_name);

    if (!ghost_file)
    {
        _ghost_dprf("Could not open file to save ghosts.");
        return;
    }

    writer outw(g_file_name, ghost_file);

    write_ghost_version(outw);
    tag_write_ghosts(outw, leftovers);

    lk_close(ghost_file);

    _ghost_dprf("Saved ghosts (%s).", g_file_name.c_str());
}