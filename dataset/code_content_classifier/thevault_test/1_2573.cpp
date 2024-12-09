string LinuxParser::Command(int pid) { 
    string command;
    string line;
    std::ifstream stream(kProcDirectory + "/" + to_string(pid) + kCmdlineFilename);
    if (stream) {
        std::getline(stream,line);
        std::istringstream linestream(line);
        linestream >> command; 
        }
        return command;
    }