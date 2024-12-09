void Results::readResults(){
  std::ifstream dbfile;
  dbfile.open(resultsDB);
  
  if(dbfile){
    std::string line;
    std::vector<std::string> tokens;

    // throw header line in file away
    std::getline(dbfile, line);
    while(std::getline(dbfile,line)){
      Player player;
      
      std::istringstream sline(line);
      std::string token;
      while(std::getline(sline, token, '\t')){
        tokens.push_back(token);
      }

      player.setName(tokens[0]);
      player.setScore(stoi(tokens[1]));
      player.setSnakeSize(stoi(tokens[2]));
      
      resultsTable->push_back(&player); // how to push player into vector as a reference or a pointer?
    }
    
    dbfile.close();
  }
}