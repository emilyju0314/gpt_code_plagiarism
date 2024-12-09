string LinuxParser::Ram(int pid) {
    string key;
    int temp_memory,memory;
    string line;
    std::ifstream stream(kProcDirectory  + "/" + to_string(pid) + kStatusFilename);
    if (stream) {
        while(std::getline(stream,line)){
            std::istringstream linestream(line);
            while(linestream >> key >> temp_memory){
                if (key == "VmSize:") {
                    memory = temp_memory;
                    break;
                } 
            }
        }
    }
  return to_string((memory / 1000)); // in MB
}