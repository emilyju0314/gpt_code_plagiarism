void Room::set_event(int new_event){
  
   switch(new_event){
       case 2:
           events = new Wumpus;
           break;
       case 3:
           events = new Gold;
           break;
       case 4:
           events = new Pit;
           break;
       case 5:
           events = new Bat;
           break;
       default:
           events = new Event;
           break;
   }
}