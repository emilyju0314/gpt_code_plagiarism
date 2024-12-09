bool player::level_visited(const level_id &level)
{
    // `is_existing_level` is not reliable after the game end, because the
    // save no longer exists, so we ignore it for printing morgues
    if (!is_existing_level(level) && you.save)
        return false;
    const auto &visited = props[VISITED_LEVELS_KEY].get_table();
    return visited.exists(level.describe());
}