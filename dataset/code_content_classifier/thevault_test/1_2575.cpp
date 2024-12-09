string LinuxParser::Uid(int pid) { 
    string key,temp_uid,uid;
    string line;
    std::ifstream stream(kProcDirectory + "/" + to_string(pid) + kStatusFilename);
    if (stream) {
        while(std::getline(stream,line)){
            std::istringstream linestream(line);
            while(linestream >> key >> temp_uid){
                if ( key == "Uid:") {
                  uid = temp_uid;
                  break;
                }
            }
        }
    }
    return uid;
}