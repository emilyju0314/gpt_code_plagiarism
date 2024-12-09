inline std::string fmtstr(const std::string& fmt, const std::vector<std::string>& args) {
    std::string s = fmt;
    for (auto&& e : args) {
      std::string::size_type n = s.find("%s");
      if (n==std::string::npos) return "** Ill-formated string ** " + fmt;
      s.replace(n, 2, e);
    }
    return s;
  }