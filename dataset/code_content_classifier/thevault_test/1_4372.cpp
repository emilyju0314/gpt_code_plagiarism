bool ReadPotentials(const string &weight_type,
                    const string& filename,
                    vector<WeightClass>* potential) {
  ifstream strm(filename.c_str());
  if (!strm) {
    LOG(ERROR) << "ReadPotentials: Can't open file: " << filename;
    return false;
  }

  const int kLineLen = 8096;
  char line[kLineLen];
  size_t nline = 0;

  potential->clear();
  while (strm.getline(line, kLineLen)) {
    ++nline;
    vector<char *> col;
    SplitToVector(line, "\n\t ", &col, true);
    if (col.size() == 0 || col[0][0] == '\0')  // empty line
      continue;
    if (col.size() != 2) {
      LOG(ERROR) << "ReadPotentials: Bad number of columns, "
                 << "file = " << filename << ", line = " << nline;
      return false;
    }

    ssize_t s = StrToInt64(col[0], filename, nline, false);
    WeightClass weight(weight_type, col[1]);

    while (potential->size() <= s)
      potential->push_back(WeightClass::Zero());
    (*potential)[s] = weight;
  }
  return true;
}