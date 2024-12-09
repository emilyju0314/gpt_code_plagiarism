ifpstream::ifpstream(std::string const &filename, ios_base::openmode const mode) {
  mode_ = mode;
  if (rtt_c4::node() == 0) {
    in_.open(filename, mode);
    Insist(in_, filename + " does not exist");
  }
}