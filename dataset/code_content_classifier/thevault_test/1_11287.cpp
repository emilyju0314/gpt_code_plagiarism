void subscribe_socket::disconnect(std::string objectkey) {
  std::lock_guard<mutex> guard(lock);
  if (publishers.count(objectkey)) {
    nn_shutdown(z_socket, publishers[objectkey]);
    publishers.erase(objectkey);
  }
}