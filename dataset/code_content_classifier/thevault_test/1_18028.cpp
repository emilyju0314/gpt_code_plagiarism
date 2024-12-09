string LinuxParser::Ram(int pid) {
  string name = "VmData";
  string title, value;
  std::ifstream stream(kProcDirectory + to_string(pid) + kStatusFilename);
  string line;
  while (std::getline(stream, line)){
    if(line.compare(0, name.size(), name) == 0){
      std::istringstream linestream(line);
      linestream >> title >> value;
      break;
    }
  }
  if (value == ""){
    return "0";
  }

  value = to_string(stof(value.c_str())/1024);
  return value.substr(0,6); 
}