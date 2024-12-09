bool turtle::get_next(int &new_x, int &new_y, const int game_map[][150])
{
    // record passing on
    if (last) delete last;
    last = now; now = NULL;
    // same place - stop
    if (game_map[x][y] == 4)
    {
        now = new turtle::record(last, x, y, this);
        new_x = x; new_y = y;
        return true;
    }
    // human in robot's sight?
    int hx, hy;
    bool around = turtle::scan(x, y, r, hx, hy, game_map);
    if (around) turtle::cheak_wall(x, y, hx, hy, game_map);
    now = new turtle::record(last, hx, hy, this);
    // human in sight - track
    if (now -> insight)
    {
        if (plan) delete plan;
        x += sgn(now->hx - x);
        y += sgn(now->hy - y);
        new_x = x; new_y = y;
        return true;
    }
    // human out of sight - search
    else
    {
        if (!plan) plan = new turtle::search_plan(this);
        if (!plan->move(this)) return false;
        new_x = x; new_y = y;
        return true;
    }
}