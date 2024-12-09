int glob_ls_impl(std::string url, std::string glob) {
  try {
    size_t ctr = 0;
    auto response = graphlab::fileio::get_directory_listing(url);
    std::regex glob_regex(glob_to_regex(glob));
    for(auto entry: response) {
      if (std::regex_match(graphlab::fileio::get_filename(entry.first), glob_regex)) {
        std::cout << graphlab::sanitize_url(entry.first);
        ++ctr;
        if (entry.second == graphlab::fileio::file_status::DIRECTORY) {
          std::cout << "/";
        }
        std::cout << "\n";
      }
    } 
    std::cout << "\n";
    std::cout << ctr << " entries found\n";
  } catch (std::string s) {
    std::cerr << s << "\n";
    return 1;
  }
  std::cout << "\n";
  return 0;
}