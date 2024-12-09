float LinuxParser::MemoryUtilization() {
  string name_1{"MemTotal"};
  string name_2{"MemFree"};
  string name_3{"Buffers"};
  string line;
  float totalMem;
  float freeMem;
  float buffers;
  int counter = 0;
  std::ifstream stream(kProcDirectory + kMeminfoFilename);
  if (!stream) {
    throw std::runtime_error("Non - existing file");
  }
  while (std::getline(stream, line)) {
    if (counter == 3) {
      break;
    }
    if (line.compare(0, name_1.size(), name_1) == 0) {
      std::istringstream buf(line);
      std::istream_iterator<std::string> beging(buf), end;
      std::vector<std::string> words(beging, end);
      totalMem = std::stof(words[1]);
      counter++;
    } else if (line.compare(0, name_2.size(), name_2) == 0) {
      std::istringstream buf(line);
      std::istream_iterator<std::string> beging(buf), end;
      std::vector<std::string> words(beging, end);
      freeMem = std::stof(words[1]);
      counter++;
    } else if (line.compare(0, name_3.size(), name_3) == 0) {
      std::istringstream buf(line);
      std::istream_iterator<std::string> beging(buf), end;
      std::vector<std::string> words(beging, end);
      buffers = std::stof(words[1]);
      counter++;
    }
  }
  return float((1 - (freeMem / (totalMem - buffers))));
}