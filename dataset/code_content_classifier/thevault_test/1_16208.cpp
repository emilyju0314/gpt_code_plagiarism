void apply_discount(Travel & travel, vector<vector<string> >&alliances){
  if(travel.flights.size()>0)
    travel.flights[0].discout = 1;
  if(travel.flights.size()>1){
    for(unsigned int i=1; i<travel.flights.size(); i++){
      Flight& flight_before = travel.flights[i-1];
      Flight& current_flight = travel.flights[i];
      if(has_just_traveled_with_company(flight_before, current_flight)){
	flight_before.discout = 0.7;
	current_flight.discout = 0.7;
      }else if(has_just_traveled_with_alliance(flight_before, current_flight, alliances)){
	if(flight_before.discout >0.8)
	  flight_before.discout = 0.8;
	current_flight.discout = 0.8;
      }else{
	current_flight.discout = 1;
      }
    }
  }
}