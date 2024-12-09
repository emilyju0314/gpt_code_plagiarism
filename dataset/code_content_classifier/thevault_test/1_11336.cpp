inline std::vector<std::string> strsplit(const std::string& str, 
                                           const std::string& splitchars,
                                           const bool auto_trim = false) {
    std::vector<std::string> tokens;
    for(size_t beg = 0, end = 0; end != std::string::npos; beg = end+1) {
      end = str.find_first_of(splitchars, beg);
      if(auto_trim) {
        if(end - beg > 0) {
          std::string tmp = trim(str.substr(beg, end - beg));
          if(!tmp.empty()) tokens.push_back(tmp);
        }
      } else tokens.push_back(str.substr(beg, end - beg));
    }
    return tokens;
    // size_t pos = 0;
    // while(1) {
    //   size_t nextpos = s.find_first_of(splitchars, pos);
    //   if (nextpos != std::string::npos) {
    //     ret.push_back(s.substr(pos, nextpos - pos));
    //     pos = nextpos + 1;
    //   } else {
    //     ret.push_back(s.substr(pos));
    //     break;
    //   }
    // }
    // return ret;
  }