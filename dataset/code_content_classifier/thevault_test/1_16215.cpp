void print_flight(Flight& flight, ofstream& output){
  struct tm * take_off_t, *land_t;
  take_off_t = gmtime(((const time_t*)&(flight.take_off_time)));
  output<<flight.company<<"-";
  output<<""<<flight.id<<"-";
  output<<flight.from<<" ("<<(take_off_t->tm_mon+1)<<"/"<<take_off_t->tm_mday<<" "<<take_off_t->tm_hour<<"h"<<take_off_t->tm_min<<"min"<<")"<<"/";
  land_t = gmtime(((const time_t*)&(flight.land_time)));
  output<<flight.to<<" ("<<(land_t->tm_mon+1)<<"/"<<land_t->tm_mday<<" "<<land_t->tm_hour<<"h"<<land_t->tm_min<<"min"<<")-";
  output<<flight.cost<<"$"<<"-"<<flight.discout*100<<"%"<<endl;

}