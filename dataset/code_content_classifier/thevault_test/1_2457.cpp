void RTT_Format_Reader::readEndKeyword(ifstream &meshfile) {
  string dummyString;

  meshfile >> dummyString;
  Insist(dummyString == "end_rtt_mesh", "Invalid mesh file: RTT file missing end");
  std::getline(meshfile, dummyString);
}