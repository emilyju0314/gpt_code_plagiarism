void Game::print_grid()
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
           switch(grid[i][j].get_player())
           {
               case 0:
                   cout << "|";
                   cout << "     ";
                   break;
               case 1:
                   cout << "|";
                   cout << "  *  ";
                   break;
                default:
                   cout << "|";
                   cout << "     ";
                   break;
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