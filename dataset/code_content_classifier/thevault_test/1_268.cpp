void Game::print_event()
{
    wumpus_near = false;
    cout<<"~~~~~~~~~~~~~~~~~"<<endl;
    if((player_x+1) < size && grid[player_x+1][player_y].get_event_type()!=1)
    {
        cout << grid[player_x+1][player_y].get_event() << endl;

            if (grid[player_x+1][player_y].get_event_type() == 2)
            {
                wumpus_near = true;
            }
            
    }
    if((player_x-1) >= 0 && grid[player_x-1][player_y].get_event_type()!=1)
    {
        cout << grid[player_x-1][player_y].get_event() << endl;

            if (grid[player_x-1][player_y].get_event_type() == 2)
            {
                wumpus_near = true;
            }
            
    }
    if((player_y+1) < size && grid[player_x][player_y+1].get_event_type()!=1)
    {
        cout << grid[player_x][player_y+1].get_event() << endl;

            if (grid[player_x][player_y+1].get_event_type() == 2)
            {
                wumpus_near = true;
            }
            
    }
    if((player_y-1) >=0 && grid[player_x][player_y-1].get_event_type()!=1)
    {
        cout << grid[player_x][player_y-1].get_event() << endl;

            if (grid[player_x][player_y-1].get_event_type() == 2)
            {
                wumpus_near = true;
            }
            
    }
    cout<<"~~~~~~~~~~~~~~~~~"<<endl;
}