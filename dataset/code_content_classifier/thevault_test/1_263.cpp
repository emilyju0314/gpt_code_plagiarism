void Game::print_grid_debugg()
{
    for(int i = 0; i < size; i++)
   {
    cout<<"#";
        
        for(int k = 0; k < size; k++)
        {
         
         cout << "-----";
         cout << "#";
         
        }
    
    cout<<"\n";
       
       for(int j = 0; j < size; j++)
       {
           switch(grid[i][j].get_event_type())
           {
               case 1:
                   if(grid[i][j].get_player() == true)
                   {
                       cout << "|";
                       cout << "  *  ";
                   }
                   else if (grid[i][j].get_player() == false)
                   {
                       cout << "|";
                       cout << "     ";
                   }
                   
                   break;
               case 2:
                   cout << "|";
                   cout << "  W  ";
                   break;
               case 3:
                   cout << "|";
                   cout << "  G  ";
                   break;
               case 4:
                   cout << "|";
                   cout << "  P  ";
                   break;
               case 5:
                   cout << "|";
                   cout << "  B  ";
                   break;
               default:
                   cout<< "|";
                   cout<< "     ";
           }
       }

       cout<<"|";
       cout<<"\n";
   }
   cout << "#";

   for(int i = 0; i < size; i++)
   {
   cout << "-----";
   cout << "#";
   }
   cout << "\n";

}