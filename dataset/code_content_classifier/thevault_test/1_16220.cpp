void parse_alliance(vector<string> &alliance, string line){
  vector<string> splittedLine;
  split_string(splittedLine, line, ';');
  for(unsigned int i=0; i<splittedLine.size(); i++){
    alliance.push_back(splittedLine[i]);
  }
}