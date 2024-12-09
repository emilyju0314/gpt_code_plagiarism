void parse_flight(vector<Flight>& flights, string& line){
  vector<string> splittedLine;
  split_string(splittedLine, line, ';');
  if(splittedLine.size() == 7){
    Flight flight;
    flight.id = splittedLine[0];
    flight.from = splittedLine[1];
    flight.take_off_time = convert_string_to_timestamp(splittedLine[2].c_str());
    flight.to = splittedLine[3];
    flight.land_time = convert_string_to_timestamp(splittedLine[4].c_str());
    flight.cost = atof(splittedLine[5].c_str());
    flight.company = splittedLine[6];
    flights.push_back(flight);
  }
}