void parse_flights(vector<Flight>& flights, string filename){
  string line = "";
  ifstream file;
  file.open(filename.c_str());
  if(!file.is_open()){
    cerr<<"Problem while opening the file "<<filename<<endl;
    exit(0);
  }
  while (!file.eof())
    {
      getline(file, line);
      parse_flight(flights, line);
    }
}