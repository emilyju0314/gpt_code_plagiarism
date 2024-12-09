void output_work_hard(vector<Flight>& flights, Parameters& parameters, vector<vector<string> >& alliances){
  ofstream output;
  output.open(parameters.work_hard_file.c_str());
  Travel travel = work_hard(flights, parameters, alliances);
  output<<"“Work Hard” Proposition :"<<endl;
  print_travel(travel, alliances, output);
  output.close();
}