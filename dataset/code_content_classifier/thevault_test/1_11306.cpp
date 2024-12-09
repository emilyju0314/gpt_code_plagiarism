std::string _get_unique_directory(const std::string& file, size_t line) {
  
  std::ostringstream ss;

  ss << "./archive_" << getpid() << "_";
  
  ss  << "t" << thread::thread_id() << "__";

  ss << random::fast_uniform<size_t>(0, size_t(-1)); 

  return ss.str();
}