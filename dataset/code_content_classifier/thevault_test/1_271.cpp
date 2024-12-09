void Game::wumpus_move()
{
    cout << "You missed your shoot"<<endl;
    arrows --;
    cout << "Arrows left: "<< arrows <<endl;
    int wumpus_rand = rand()%4;
    if(wumpus_rand != 4)
    {
        cout << "Wumpus awake and he is moving"<<endl;
        grid[wumpus_x][wumpus_y].set_event_type(0);
        //grid[wumpus_x][wumpus_y].set_event(0);
        pop_event(2);
        //grid[wumpus_x][wumpus_y].set_event(2);

    }
}