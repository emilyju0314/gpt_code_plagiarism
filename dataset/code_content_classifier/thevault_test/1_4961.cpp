std::string_view stripVendor(std::string_view view) {
  for (auto const &it : vendors) {
    // Don't strip if it's all that's left
    if (view == it)
      break;

    if (strncmp(view.data() + view.size() - it.size(), it.data(), it.size()) == 0) {
      view = view.substr(0, view.size() - it.size());
      break;
    }
  }

  return view;
}