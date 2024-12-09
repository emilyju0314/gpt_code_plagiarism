int cp_impl(std::string srcpath, std::string dstpath) {

  auto src_type = graphlab::fileio::get_file_status(srcpath);
  auto dst_type = graphlab::fileio::get_file_status(dstpath);
  if (src_type == graphlab::fileio::file_status::MISSING) {
    // missing source file
    std::cerr << "Source file missing\n";
    return 1;
  } else if (src_type == graphlab::fileio::file_status::REGULAR_FILE) {
    // source file is a single file
    if (dst_type == graphlab::fileio::file_status::MISSING ||
        dst_type == graphlab::fileio::file_status::REGULAR_FILE) {
      // target is missing, or I am overwriting
      file_copy(srcpath, dstpath);
    } else { 
      // if target is a directory... we need to come up with the target filename
      file_copy(srcpath, dstpath + "/" + graphlab::fileio::get_filename(srcpath));
    }
  } else if (src_type == graphlab::fileio::file_status::DIRECTORY) {
    // copying a directory
    if (dst_type == graphlab::fileio::file_status::REGULAR_FILE) {
      std::cerr << "Cannot create target directory. File already exists";
      return 1;
    } else {
      recursive_copy(srcpath, dstpath + "/" + graphlab::fileio::get_filename(srcpath));
    }
  }
  return 0;
}