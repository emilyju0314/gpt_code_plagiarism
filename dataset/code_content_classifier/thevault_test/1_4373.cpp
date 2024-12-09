bool WritePotentials(const string& filename,
                     const vector<WeightClass>& potential) {
  ostream *strm = &cout;
  if (!filename.empty()) {
    strm = new ofstream(filename.c_str());
    if (!*strm) {
      LOG(ERROR) << "WritePotentials: Can't open file: " << filename;
      delete strm;
      return false;
    }
  }

  strm->precision(9);
  for (ssize_t s = 0; s < potential.size(); ++s)
    *strm << s << "\t" << potential[s] << "\n";

  if (!*strm)
    LOG(ERROR) << "WritePotentials: Write failed: "
               << (filename.empty() ? "standard output" : filename);
  bool ret = *strm;
  if (strm != &cout)
    delete strm;
  return ret;
}