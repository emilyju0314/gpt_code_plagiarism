void barStripper(Tab& t, string s)
{
  // Start of string for Tab.
  string filename = "";

  // Extract all filenames from the command line.
  for (int i = 0; i < int(s.size()); ++i) {
    if (s[i] == '|') {
      if (filename.size() > 0) {
        t[t.entries()] = filename;
      }
      filename = "";
    }
    else if (s[i] != ' ') {
      filename += s[i];
    }
  }

  // Grab the last filename.
  if (filename.size() > 0) {
    t[t.entries()] = filename;
  }
}