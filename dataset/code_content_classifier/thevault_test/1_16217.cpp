void split_string(vector<string>& result, string line, char separator){
  while(line.find(separator) != string::npos){
    size_t pos = line.find(separator);
    result.push_back(line.substr(0, pos));
    line = line.substr(pos+1);
  }
  result.push_back(line);
}