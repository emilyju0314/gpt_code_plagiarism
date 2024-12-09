void fill_travel(vector<Travel>& travels, vector<Flight>& flights, string starting_point, unsigned long t_min, unsigned long t_max){
  for(unsigned int i=0; i< flights.size(); i++){
    if(flights[i].from == starting_point &&
       flights[i].take_off_time >= t_min &&
       flights[i].land_time <= t_max){
      Travel t;
      t.flights.push_back(flights[i]);
      travels.push_back(t);
    }
  }
}