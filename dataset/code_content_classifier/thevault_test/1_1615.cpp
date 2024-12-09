bool Excluded(int fileNum) {
  map<int, bool>::iterator it = excludedFiles.find(fileNum);

  if(it == excludedFiles.end()) {
    return false;
  }
  else {
    return it->second;
  }
}