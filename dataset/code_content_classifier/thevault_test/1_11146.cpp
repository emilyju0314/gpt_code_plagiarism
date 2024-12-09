bool Classify::WriteTRFile(const char *filename) {
  bool result = false;
  std::string tr_filename = filename;
  tr_filename += ".tr";
  FILE *fp = fopen(tr_filename.c_str(), "wb");
  if (fp) {
    result = tesseract::Serialize(fp, &tr_file_data_[0], tr_file_data_.length());
    fclose(fp);
  }
  tr_file_data_.resize(0);
  return result;
}