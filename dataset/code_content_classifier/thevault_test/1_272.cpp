void Game::shoot_arrow(string where)
{
    int pos_x = player_x;
    int pos_y = player_y;

    if(wumpus == true)
    {
        cout<<"Wumpus already killed"<<endl;
        return;
    }
    for (int i = 0; i < 3; i++)
    {
        if (where == " w" && (pos_x-1)>=0)
        {
            pos_x--;
        }
        else if (where == " s" && (pos_x+1) < size)
        {
            pos_x++;
        }
        else if (where == " a" && (pos_y-1) >= 0)
        {
            pos_y--;
        }
        else if (where == " d" && (pos_y+1) <size)
        {
            pos_y++;
        }  
        if(grid[pos_x][pos_y].get_event_type() == 2)
        {
            cout<< "Your arrow reached Wumpus head"<<endl;
             //remove(wumpus_x,wumpus_y);
            grid[pos_x][pos_y].set_event_type(0);
            wumpus = true;
        }
    }
    if (wumpus == false)
    {
        wumpus_move();
    }
}