void merge_path(vector<Travel>& travel1, vector<Travel>& travel2){
  vector<Travel> result;
  for(unsigned int i=0; i<travel1.size(); i++){
    Travel t1 = travel1[i];
    for(unsigned j=0; j<travel2.size(); j++){
      Travel t2 = travel2[j];
      Flight last_flight_t1 = t1.flights.back();
      Flight first_flight_t2 = t2.flights[0];
      if(last_flight_t1.land_time < first_flight_t2.take_off_time){
	Travel new_travel = t1;
	new_travel.flights.insert(new_travel.flights.end(), t2.flights.begin(), t2.flights.end());
	result.push_back(new_travel);
      }
    }
  }
  travel1 = result;
}