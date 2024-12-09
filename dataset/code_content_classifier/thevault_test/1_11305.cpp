void _add_directory_to_deleter(const std::string& name) {

  __list_of_directories_lock.lock();
  
  if(!archive_directory_deleter_added) {
    std::atexit(_archive_directory_deleter);
    archive_directory_deleter_added = true;
  }
        
  __list_of_directories_to_clean_up.push_back(name);
  
  __list_of_directories_lock.unlock();
}