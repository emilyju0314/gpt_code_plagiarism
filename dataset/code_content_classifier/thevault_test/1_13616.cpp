void String::LTrim(std::string *s) {
  (*s).erase(
      (*s).begin(),
      std::find_if(
          (*s).begin(),
          (*s).end(),
          std::not1(std::ptr_fun<int, int>(std::isspace))));
}