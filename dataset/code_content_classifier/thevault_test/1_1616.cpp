bool Excluded(int fileNum, int frameletNum, double &stdev) {
  if(Excluded(fileNum)) return true;

  map< pair<int, int>, double>::iterator it = excludedFramelets.find(pair<int, int>(fileNum, frameletNum));

  if(it == excludedFramelets.end()) {
    return false;
  }
  else {
    stdev = it->second;
    return true;
  }
}