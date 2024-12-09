void Game::print_status()
{
    if(gold == true && wumpus == true)//win
    {
        cout<<"CURRENT PROGRESS:"<<endl;
        cout << pos1 << "\n\n";
        alive = false;
        
    }
    else if(arrows <= 0 && wumpus == false)
    {
        cout <<arrow1<<endl;
        alive = false;
    }
    else if(arrows <= 0 && wumpus == true)
    {
        cout <<arrow1<<endl;
    }
    else if(gold == false && wumpus == true)//need gold
    {
        cout<<"CURRENT PROGRESS:"<<endl;
        cout << pos3 << "\n\n";
        
    }
    else if(gold == true && wumpus == false)//kill wumpus
    {
        cout<<"CURRENT PROGRESS:"<<endl;
        cout << pos2 << "\n\n";
    }
}