void Plumbing::EnumerateLayers(const std::string *prefix, std::vector<std::string> &layers) const {
  for (size_t i = 0; i < stack_.size(); ++i) {
    std::string layer_name;
    if (prefix) {
      layer_name = *prefix;
    }
    layer_name += ":" + std::to_string(i);
    if (stack_[i]->IsPlumbingType()) {
      auto *plumbing = static_cast<Plumbing *>(stack_[i]);
      plumbing->EnumerateLayers(&layer_name, layers);
    } else {
      layers.push_back(layer_name);
    }
  }
}