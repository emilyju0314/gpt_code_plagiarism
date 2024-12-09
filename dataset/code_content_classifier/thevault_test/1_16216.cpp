void read_parameters(Parameters& parameters, int argc, char **argv){
  for(int i=0; i<argc; i++){
    string current_parameter = argv[i];
    if(current_parameter == "-from"){
      parameters.from = argv[++i];
    }else if(current_parameter == "-arrival_time_min"){
      parameters.ar_time_min = convert_string_to_timestamp(argv[++i]);
    }else if(current_parameter == "-arrival_time_max"){
      parameters.ar_time_max = convert_string_to_timestamp(argv[++i]);
    }else if(current_parameter == "-to"){
      parameters.to = argv[++i];
    }else if(current_parameter == "-departure_time_min"){
      parameters.dep_time_min = convert_string_to_timestamp(argv[++i]);
    }else if(current_parameter == "-departure_time_max"){
      parameters.dep_time_max = convert_string_to_timestamp(argv[++i]);
    }else if(current_parameter == "-max_layover"){
      parameters.max_layover_time = atol(argv[++i]);
    }else if(current_parameter == "-vacation_time_min"){
      parameters.vacation_time_min = atol(argv[++i]);
    }else if(current_parameter == "-vacation_time_max"){
      parameters.vacation_time_max = atol(argv[++i]);
    }else if(current_parameter == "-vacation_airports"){
      while(i+1 < argc && argv[i+1][0] != '-'){
	parameters.airports_of_interest.push_back(argv[++i]);
      }
    }else if(current_parameter == "-flights"){
      parameters.flights_file = argv[++i];
    }else if(current_parameter == "-alliances"){
      parameters.alliances_file = argv[++i];
    }else if(current_parameter == "-work_hard_file"){
      parameters.work_hard_file = argv[++i];
    }else if(current_parameter == "-play_hard_file"){
      parameters.play_hard_file = argv[++i];
    }else if(current_parameter == "-nb_threads"){
      parameters.nb_threads = atoi(argv[++i]);
      omp_set_num_threads(parameters.nb_threads);
    }

  }
}