void parse_alliances(vector<vector<string> > &alliances, string filename){
  string line = "";
  ifstream file;

  file.open(filename.c_str());
  if(!file.is_open()){
    cerr<<"Problem while opening the file "<<filename<<endl;
    exit(0);
  }
  while (!file.eof())
    {
      vector<string> alliance;
      getline(file, line);
      parse_alliance(alliance, line);
      alliances.push_back(alliance);
    }
}