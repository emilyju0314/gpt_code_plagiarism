bool pregen_dungeon(const level_id &stopping_point)
{
    // TODO: the is_valid() check here doesn't look quite right to me, but so
    // far I can't get it to break anything...
    if (stopping_point.is_valid()
        || stopping_point.branch != NUM_BRANCHES &&
           is_random_subbranch(stopping_point.branch) && you.wizard)
    {
        if (you.save->has_chunk(stopping_point.describe()))
            return false;

        if (!_branch_pregenerates(stopping_point.branch))
            return generate_level(stopping_point);
    }

    vector<level_id> to_generate;
    bool at_end = false;
    for (auto br : branch_generation_order)
    {
        if (br == BRANCH_ZIGGURAT &&
            stopping_point.branch == BRANCH_ZIGGURAT)
        {
            // zigs delete levels as they go, so don't catchup when we're
            // already in one. Zigs are only handled this way so that everything
            // else generates first.
            to_generate.push_back(stopping_point);
            continue;
        }
        // TODO: why is dungeon invalid? it's not set up properly in
        // `initialise_branch_depths` for some reason. The vestibule is invalid
        // because its depth isn't set until the player actually enters a
        // portal, similarly for other portal branches.
        if (br < NUM_BRANCHES &&
            (brentry[br].is_valid()
             || br == BRANCH_DUNGEON || br == BRANCH_VESTIBULE
             || !is_connected_branch(br)))
        {
            for (int i = 1; i <= brdepth[br]; i++)
            {
                level_id new_level = level_id(br, i);
                if (you.save->has_chunk(new_level.describe()))
                    continue;
                to_generate.push_back(new_level);

                if (br == stopping_point.branch
                    && (i == stopping_point.depth || i == brdepth[br]))
                {
                    at_end = true;
                    break;
                }
            }
        }
        if (at_end)
            break;
    }

    if (to_generate.size() == 0)
    {
        dprf("levelgen: No valid levels to generate.");
        return false;
    }
    else if (to_generate.size() == 1)
        return generate_level(to_generate[0]); // no popup for this case
    else
    {
        // be sure that AK start doesn't interfere with the builder
        unwind_var<game_chapter> chapter(you.chapter, CHAPTER_ORB_HUNTING);

        ui::progress_popup progress("Generating dungeon...\n\n", 35);
        progress.advance_progress();

        // in normal usage if we get to here, something will generate. But it
        // is possible to call this in a way that doesn't lead to generation.
        bool generated = false;

        for (const level_id &new_level : to_generate)
        {
            string status = "\nbuilding ";

            switch (new_level.branch)
            {
            case BRANCH_SPIDER:
            case BRANCH_SNAKE:
                status += "a lair branch";
                break;
            case BRANCH_SHOALS:
            case BRANCH_SWAMP:
                status += "another lair branch";
                break;
            default:
                status += branches[new_level.branch].longname;
                break;
            }
            progress.set_status_text(status);
            dprf("Pregenerating %s:%d",
                branches[new_level.branch].abbrevname, new_level.depth);
            progress.advance_progress();
            generated = generate_level(new_level) || generated;
        }

        return generated;
    }
}