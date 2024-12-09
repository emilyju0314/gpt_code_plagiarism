void Game::set_grid()
{
    pop_event(1);
    pop_event(2);
    pop_event(3);
    
    for (int j = 0; j < 2; j++)
    {
        pop_event(5);
    }
    for (int i = 0; i < 2; i++)
    {
        pop_event(4);
    }
    
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if(grid[i][j].get_event_type() !=1)
                grid[i][j].set_event(grid[i][j].get_event_type());
        }
        
    }
    
}