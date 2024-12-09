char * newCString(const std::string& src) {      
      char * cpy = new char[src.length() + 1];
      strncpy(cpy, src.c_str(), src.length());
      cpy[src.length()] = 0;

      return cpy;
}