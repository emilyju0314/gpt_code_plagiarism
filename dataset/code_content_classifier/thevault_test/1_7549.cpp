bool load_ghosts(int max_ghosts, bool creating_level)
{
    ASSERT(you.transit_stair == DNGN_UNSEEN || creating_level);
    ASSERT(!you.entering_level || creating_level);
    ASSERT(!creating_level
           || (you.entering_level && you.transit_stair != DNGN_UNSEEN));
    // Only way to load a ghost without creating a level is via a wizard
    // command.
    ASSERT(creating_level || (crawl_state.prev_cmd == CMD_WIZARD));

#ifdef BONES_DIAGNOSTICS
    // this is pretty hacky, but arguably cleaner than what it is replacing.
    // The effect is to show bones diagnostic messages on wizmode builds during
    // level building
    unwind_var<command_type> last_cmd(crawl_state.prev_cmd, creating_level ?
        CMD_WIZARD : crawl_state.prev_cmd);
#endif

    vector<ghost_demon> loaded_ghosts = _load_ephemeral_ghosts();

    _ghost_dprf("Loaded ghost file with %u ghost(s), will attempt to place %d of them",
             (unsigned int)loaded_ghosts.size(), max_ghosts);

    bool ghost_errors = false;

    max_ghosts = max_ghosts <= 0 ? loaded_ghosts.size()
                                 : min(max_ghosts, (int) loaded_ghosts.size());
    int placed_ghosts = 0;

    // Translate ghost to monster and place.
    while (!loaded_ghosts.empty() && placed_ghosts < max_ghosts)
    {
        monster * const mons = get_free_monster();
        if (!mons)
            break;

        mons->set_new_monster_id();
        mons->set_ghost(loaded_ghosts[0]);
        mons->type = MONS_PLAYER_GHOST;
        mons->ghost_init();

        loaded_ghosts.erase(loaded_ghosts.begin());
        placed_ghosts++;

        if (!mons->alive())
        {
            _ghost_dprf("Placed ghost is not alive.");
            ghost_errors = true;
        }
        else if (mons->type != MONS_PLAYER_GHOST)
        {
            _ghost_dprf("Placed ghost is not MONS_PLAYER_GHOST, but %s",
                 mons->name(DESC_PLAIN, true).c_str());
            ghost_errors = true;
        }
    }

    if (placed_ghosts < max_ghosts)
    {
        _ghost_dprf("Unable to place %u ghost(s)", max_ghosts - placed_ghosts);
        ghost_errors = true;
    }
#ifdef BONES_DIAGNOSTICS
    if (ghost_errors)
        more();
#endif

    // resave any unused ghosts
    if (!loaded_ghosts.empty())
        save_ghosts(loaded_ghosts);

    return true;
}