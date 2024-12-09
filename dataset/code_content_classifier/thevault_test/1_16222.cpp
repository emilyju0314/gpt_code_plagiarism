bool nerver_traveled_to(Travel travel, string city){
  for(unsigned int i=0; i<travel.flights.size(); i++)
    if(travel.flights[i].from == city || travel.flights[i].to == city)
		return false;
  return true;
}