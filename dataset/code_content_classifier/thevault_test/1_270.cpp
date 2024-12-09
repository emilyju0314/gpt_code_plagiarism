void Game::bat_move()
{
    grid[player_x][player_y].set_player(false);
    int pos_x, pos_y;
    bool position = false;
    while (position == false)
    {
        pos_x = rand()%size;
        pos_y = rand()%size;
            
        if(grid[pos_x][pos_y].get_event_type()==2||
        grid[pos_x][pos_y].get_event_type()==3||
        grid[pos_x][pos_y].get_event_type()==4)
        {
        player_x = pos_x;
        player_y = pos_y;
        grid[player_x][player_y].set_player(false);
        grid[player_x][player_y].set_player(true);
        encounter();
        position = true;
        }
        else if(grid[pos_x][pos_y].get_event_type()==1||
        grid[pos_x][pos_y].get_event_type()==0)
        {
        player_x = pos_x;
        player_y = pos_y;
        grid[player_x][player_y].set_player(false);
        grid[player_x][player_y].set_player(true);
        grid[player_x][player_y].set_event_type(1);
        position = true;
        }
        else
        {
            position = false;
        }
        
    }
}