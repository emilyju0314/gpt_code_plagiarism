void human::get_next(int &new_x, int &new_y, const int game_map[][150]) {
    if (this->x == goalX && this->y == goalY) {
        if (game_map[this->x][this->y] == 3) {
            new_x = this->x;
            new_y = this->y;
            return; // wait
        } else if (game_map[this->x][this->y] == 4) // when turtle catch up with human
        {
            last = now;
            now = judge_room(this->x, this->y);
            next_dst(goalX, goalY);
            printf("Now in room %d and prepare to go to loc(%d, %d)", now, goalX, goalY);
            path_search(game_map);
        }
    }
    if (stepNow >= 1) {
        stepNow--;
        new_x = next[stepNow].x;
        new_y = next[stepNow].y;
    } else {
        new_x = next[stepNow].x;
        new_y = next[stepNow].y;
    }
    this->x = new_x;
    this->y = new_y;
}