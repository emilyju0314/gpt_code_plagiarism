string Format::ElapsedTime(long seconds) {
  int sec = seconds % 60;
  int min = (seconds / 60) % 60;
  int hour = (seconds / 60) / 60;
  std::string out = std::to_string(hour) + ":" + std::to_string(min) + ":" +
                    std::to_string(sec);

  return out;
}