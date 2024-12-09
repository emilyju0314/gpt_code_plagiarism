void compute_path(vector<Flight>& flights, string to, vector<Travel>& travels, unsigned long t_min, unsigned long t_max, Parameters parameters){
	vector<Travel> final_travels;
	
	//double start = omp_get_wtime();
	int aux = travels.size();

	while(travels.size() > 0)
	{
  		Travel travel = travels.back();
    	Flight current_city = travel.flights.back();
    	travels.pop_back();
    	//First, if a direct flight exist, it must be in the final travels
    	if(current_city.to == to)
		{
    	  final_travels.push_back(travel);
    	}
		else
		{
			//otherwise, we need to compute a path
      		
			#pragma omp parallel for schedule(guided)
			for(unsigned int i=0; i<flights.size(); i++)
			{
				Flight flight = flights[i];
				if(
					flight.from == current_city.to &&
	   				flight.take_off_time >= t_min &&
	   				flight.land_time <= t_max &&
	   				(flight.take_off_time > current_city.land_time) &&
	   				flight.take_off_time - current_city.land_time <= parameters.max_layover_time &&
	   				nerver_traveled_to(travel, flight.to)
				)
				{
	  				Travel newTravel = travel;
	  				newTravel.flights.push_back(flight);
	  				if(flight.to == to)
					{
	    				final_travels.push_back(newTravel);
	  				}
					else
					{
	    				travels.push_back(newTravel);
	  				}
				}
    		}
		}
	aux = travels.size();
	}
	
	//double end = omp_get_wtime();
	//printf("\nTempo do while = %f", end - start);
	
	travels = final_travels;
}