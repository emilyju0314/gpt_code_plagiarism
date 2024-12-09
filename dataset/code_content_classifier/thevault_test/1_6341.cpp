void LavaVu::parseProperties(std::string& properties, DrawingObject* obj)
{
  //Process all lines
  std::stringstream ss(properties);
  std::string line;
  while(std::getline(ss, line))
    parseProperty(line, obj);
}