Travel work_hard(vector<Flight>& flights, Parameters& parameters, vector<vector<string> >& alliances){
  vector<Travel> travels;
  //First, we need to create as much travels as it as the number of flights that take off from the
  //first city
  fill_travel(travels, flights, parameters.from, parameters.dep_time_min, parameters.dep_time_max);
  double start = omp_get_wtime();
  compute_path(flights, parameters.to, travels, parameters.dep_time_min, parameters.dep_time_max, parameters);
  double end = omp_get_wtime();
  printf("\nFirst Compute Path Time = %f", end - start); 
  
  vector<Travel> travels_back;
  //Then we need to travel back
  fill_travel(travels_back, flights, parameters.to, parameters.ar_time_min, parameters.ar_time_max);
  start = omp_get_wtime();
  compute_path(flights, parameters.from, travels_back, parameters.ar_time_min, parameters.ar_time_max, parameters);
  end = omp_get_wtime();
  printf("\nSecond Compute Path Time = %f", end - start); 
  
  merge_path(travels, travels_back);
  Travel go =  find_cheapest(travels, alliances);
  return go;
}