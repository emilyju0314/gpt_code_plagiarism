int ProcessFile(const char file_path[], const struct stat* sb = nullptr, int typeflag = FTW_F) {
  if (typeflag != FTW_F)
    return 0;

  cout << "Processing: " << file_path << endl;
  string filename(file_path);
#endif  // _WIN32

  File input_file(file_path);

  if (input_file.IsOK()) {
    size_t original_size = input_file.GetSize();

    size_t new_size = LeanifyFile(input_file.GetFilePionter(), original_size, 0, filename);

    PrintSize(original_size);
    cout << " -> ";
    PrintSize(new_size);
    cout << "\tLeanified: ";
    PrintSize(original_size - new_size);

    cout << " (" << 100 - 100.0 * new_size / original_size << "%)" << endl;

    input_file.UnMapFile(new_size);
  }

  return 0;
}