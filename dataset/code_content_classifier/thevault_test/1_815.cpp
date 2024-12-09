void split(const std::string& str, Container& cont)
{
    std::istringstream iss(str); // aus sstream?
    std::copy(std::istream_iterator<std::string>(iss),
              std::istream_iterator<std::string>(),
              std::back_inserter(cont));
}