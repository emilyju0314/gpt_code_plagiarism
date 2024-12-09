static void _place_player(dungeon_feature_type stair_taken,
                          const coord_def &return_pos,
                          const coord_def &dest_pos, const string &hatch_name)
{
    if (player_in_branch(BRANCH_ABYSS))
        you.moveto(ABYSS_CENTRE);
    else if (!return_pos.origin())
        you.moveto(return_pos);
    else
        _place_player_on_stair(stair_taken, dest_pos, hatch_name);

    // Don't return the player into walls, deep water, or a trap.
    for (distance_iterator di(you.pos(), true, false); di; ++di)
        if (you.is_habitable_feat(grd(*di))
            && !is_feat_dangerous(grd(*di), true)
            && !feat_is_trap(grd(*di)))
        {
            if (you.pos() != *di)
                you.moveto(*di);
            break;
        }

    // This should fix the "monster occurring under the player" bug.
    monster *mon = monster_at(you.pos());
    if (mon && !fedhas_passthrough(mon))
    {
        for (distance_iterator di(you.pos()); di; ++di)
        {
            if (!monster_at(*di) && mon->is_habitable(*di))
            {
                mon->move_to_pos(*di);
                return;
            }
        }

        dprf("%s under player and can't be moved anywhere; killing",
             mon->name(DESC_PLAIN).c_str());
        monster_die(*mon, KILL_DISMISSED, NON_MONSTER);
        // XXX: do we need special handling for uniques...?
    }
}