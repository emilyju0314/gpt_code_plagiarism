bool define_ghost_from_bones(monster& mons)
{
    rng::generator rng(rng::SYSTEM_SPECIFIC);

    bool used_permastore = false;

    vector<ghost_demon> loaded_ghosts = _load_ephemeral_ghosts();
    if (loaded_ghosts.empty())
    {
        loaded_ghosts = _load_permastore_ghosts();
        if (loaded_ghosts.empty())
            return false;
        used_permastore = true;
    }

    int place_i = random2(loaded_ghosts.size());
    _ghost_dprf("Loaded ghost file with %u ghost(s), placing %s",
         (unsigned int)loaded_ghosts.size(), loaded_ghosts[place_i].name.c_str());

    mons.set_ghost(loaded_ghosts[place_i]);
    mons.type = MONS_PLAYER_GHOST;
    mons.ghost_init(false);

    if (!mons.alive())
        mprf(MSGCH_ERROR, "Placed ghost is not alive.");
    else if (mons.type != MONS_PLAYER_GHOST)
    {
        mprf(MSGCH_ERROR, "Placed ghost is not MONS_PLAYER_GHOST, but %s",
             mons.name(DESC_PLAIN, true).c_str());
    }

    if (!used_permastore)
    {
        loaded_ghosts.erase(loaded_ghosts.begin() + place_i);

        if (!loaded_ghosts.empty())
            save_ghosts(loaded_ghosts);
    }
    return true;
}