auto stringToTime(std::string const &TimeString) {
  using namespace std::string_literals;
  std::regex DateTimeRegex{
      R"rr(^(\d{4})-(\d{2})-(\d{2})t(\d{2}):(\d{2}):(\d{2})z$)rr"};
  std::smatch Match;
  if (not std::regex_match(TimeString, Match, DateTimeRegex)) {
    throw std::runtime_error("The string \"" + TimeString +
                             "\" is not a valid date time string.");
  }
  auto GetValue = [](auto Match, auto MinValue, auto MaxValue,
                     auto TypeOfValue) {
    auto IntValue = std::atoi(Match.c_str());
    if (IntValue > MaxValue or IntValue < MinValue) {
      throw std::runtime_error("The value "s + std::to_string(MaxValue) +
                               " is not a valid "s + TypeOfValue + " value."s);
    }
    return IntValue;
  };
  std::tm t{};
  t.tm_year = GetValue(Match[1].str(), 1970, 3000, "year") - 1900;
  t.tm_mon = GetValue(Match[2].str(), 1, 12, "month") - 1;
  t.tm_mday = GetValue(Match[3].str(), 1, 31, "day");
  t.tm_hour = GetValue(Match[4].str(), 0, 23, "hour");
  t.tm_min = GetValue(Match[5].str(), 0, 59, "minute");
  t.tm_sec = GetValue(Match[6].str(), 0, 60, "second");
  return std::chrono::system_clock::from_time_t(timegm(&t));
}