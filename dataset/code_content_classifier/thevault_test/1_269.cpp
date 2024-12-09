void Game::encounter()
{
    if(arrows == 0 && wumpus == false)
    {
        cout << arrow1 << "\n\n";
        //return false;
    }
    else if(arrows == 0 && wumpus == true)
    {
        cout << arrow2 << "\n\n";
    }
    
    switch (grid[player_x][player_y].get_event_type())
    {
    case 1:
        
        break;
    case 2:
        cout << grid[player_x][player_y].get_in() << "\n\n";
        
        alive = false;
        //return false;
        break;
    case 3:
        cout << grid[player_x][player_y].get_in() << "\n\n";
        gold = true;
        grid[player_x][player_y].set_player(false);
        grid[player_x][player_y].set_player(true);
        grid[player_x][player_y].set_event_type(1);
        //remove(player_x,player_y);
        //return true;
        break;
    case 4: 
        cout << grid[player_x][player_y].get_in() << "\n\n";
        alive = false;
        //return false;
        break;
    case 5:
        cout << grid[player_x][player_y].get_in() << "\n\n";
        bat_move();
        //return true;
        break;
    
    default:
        break;
    }
    //return true;
}