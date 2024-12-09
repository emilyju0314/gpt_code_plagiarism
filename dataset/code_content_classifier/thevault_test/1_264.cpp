void Game::load_data(int size, string mode)
{
    if(mode == "true"||mode == "false")
    {
        
        Game g1(size, mode);
        g1.set_grid();
        g1.gameplay(mode);
        
    }
    else
    {
        cout<< "Invalid command line"<<endl;
    }
    
    
}