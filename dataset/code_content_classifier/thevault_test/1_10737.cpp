void Plumbing::SetNetworkFlags(uint32_t flags) {
  Network::SetNetworkFlags(flags);
  for (auto &i : stack_) {
    i->SetNetworkFlags(flags);
  }
}