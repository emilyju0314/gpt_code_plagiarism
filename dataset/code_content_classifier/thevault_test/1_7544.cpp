bool generate_level(const level_id &l)
{
    const string level_name = l.describe();
    if (you.save->has_chunk(level_name))
        return false;

    unwind_var<int> you_depth(you.depth, l.depth);
    unwind_var<branch_type> you_branch(you.where_are_you, l.branch);
    unwind_var<coord_def> you_saved_position(you.position);
    you.position.reset();

    // simulate a reasonable stair to enter the level with
    const dungeon_feature_type stair_taken =
          you.depth == 1
        ? (you.where_are_you == BRANCH_DUNGEON
           ? DNGN_UNSEEN
           : branches[you.where_are_you].entry_stairs)
        : DNGN_STONE_STAIRS_DOWN_I;

    unwind_var<dungeon_feature_type> stair(you.transit_stair, stair_taken);
    // TODO how necessary is this?
    unwind_bool ylev(you.entering_level, true);
    // n.b. crawl_state.generating_level is handled in builder

    _generic_level_reset();
    delete_all_clouds();
    los_changed(); // invalidate the los cache, which impacts monster placement

    // initialize env for builder
    env.turns_on_level = -1;
    tile_init_default_flavour();
    tile_clear_flavour();
    env.tile_names.clear();
    _clear_env_map();

    // finally -- everything is set up, call the builder.
    dprf("Generating new level for '%s'.", level_name.c_str());
    builder(true);

    auto &vault_list =  you.vault_list[level_id::current()];
#ifdef DEBUG
    // places where a level can generate multiple times.
    // could add portals to this list for debugging purposes?
    if (   you.where_are_you == BRANCH_ABYSS
        || you.where_are_you == BRANCH_PANDEMONIUM
        || you.where_are_you == BRANCH_BAZAAR
        || you.where_are_you == BRANCH_ZIGGURAT)
    {
        vault_list.push_back("[gen]");
    }
#endif
    const auto &level_vaults = level_vault_names();
    vault_list.insert(vault_list.end(),
                        level_vaults.begin(), level_vaults.end());

    // initialize env for a new level
    env.turns_on_level = 0;
    env.sanctuary_pos  = coord_def(-1, -1);
    env.sanctuary_time = 0;
    env.markers.init_all(); // init first, activation happens when entering
    show_update_emphasis(); // Clear map knowledge stair emphasis in env.
    update_portal_entrances();

    // save the level and associated env state
    _save_level(level_id::current());

    const string save_name = level_id::current().describe(); // should be same as level_name...

    // generate levels for all portals that branch off from here
    if (_generate_portal_levels())
    {
        // if portals were generated, we're currently elsewhere.
        ASSERT(you.save->has_chunk(save_name));
        dprf("Reloading new level '%s'.", save_name.c_str());
        _restore_tagged_chunk(you.save, save_name, TAG_LEVEL,
            "Level file is invalid.");
    }
    // ensure that there is a way of checking whether the generation process
    // effectively left us in an excursion. This shouldn't happen normally, but
    // is needed for sanity checking.
    you.on_current_level = (you_depth.original_value() == l.depth
                            && you_branch.original_value() == l.branch);
    return true;
}