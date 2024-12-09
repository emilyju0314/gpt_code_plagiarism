void print_params(Parameters &parameters){
  cout<<"From : "					<<parameters.from					<<endl;
  cout<<"To : "					<<parameters.to						<<endl;
  cout<<"dep_time_min : "			<<parameters.dep_time_min			<<endl;
  cout<<"dep_time_max : "			<<parameters.dep_time_max			<<endl;
  cout<<"ar_time_min : "			<<parameters.ar_time_min			<<endl;
  cout<<"ar_time_max : "			<<parameters.ar_time_max			<<endl;
  cout<<"max_layover_time : "		<<parameters.max_layover_time		<<endl;
  cout<<"vacation_time_min : "	<<parameters.vacation_time_min		<<endl;
  cout<<"vacation_time_max : "	<<parameters.vacation_time_max		<<endl;
  cout<<"flights_file : "			<<parameters.flights_file			<<endl;
  cout<<"alliances_file : "		<<parameters.alliances_file			<<endl;
  cout<<"work_hard_file : "		<<parameters.work_hard_file			<<endl;
  cout<<"play_hard_file : "		<<parameters.play_hard_file			<<endl;
  list<string>::iterator it = parameters.airports_of_interest.begin();
  for(; it != parameters.airports_of_interest.end(); it++)
    cout<<"airports_of_interest : "	<<*it	<<endl;
  cout<<"flights : "				<<parameters.flights_file			<<endl;
  cout<<"alliances : "			<<parameters.alliances_file			<<endl;
  cout<<"nb_threads : "			<<parameters.nb_threads				<<endl;
}