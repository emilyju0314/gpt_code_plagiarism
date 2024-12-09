void subscribe_socket::connect(std::string objectkey) {
  std::lock_guard<mutex> guard(lock);
  if (publishers.count(objectkey) == 0) {
    std::string local_address = normalize_address(objectkey);
    int ret = nn_connect(z_socket, local_address.c_str());
    if (ret > 0) {
      publishers[objectkey] = ret;
    }
  }
}