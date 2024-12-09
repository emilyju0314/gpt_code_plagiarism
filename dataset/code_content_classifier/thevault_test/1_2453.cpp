void RTT_Format_Reader::readKeyword(ifstream &meshfile) {
  string dummyString;

  meshfile >> dummyString;
  Insist(dummyString == "rtt_ascii", "Invalid mesh file: Not an RTT file");
  std::getline(meshfile, dummyString); // read and discard blank line.
}