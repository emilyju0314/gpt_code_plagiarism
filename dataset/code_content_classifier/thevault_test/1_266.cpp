void Game::pop_event(int type)
{
    srand(time(NULL));
    int posX, posY;
    bool pos = false;
    while (pos == false)
    {
        posX = rand()%size;
        posY = rand()%size;
        if(grid[posX][posY].get_event_type() == 0)
        {
            grid[posX][posY].set_event_type(type);
            pos = true;
        }
    }
    if (type == 1)
    {
        player_x = posX;
        player_y = posY;
        grid[player_x][player_y].set_player(true);
    }
    if(type == 2)
    {
        wumpus_x = posX;
        wumpus_y = posY;
    }
    
}