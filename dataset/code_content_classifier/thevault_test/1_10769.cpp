void ScrollView::Update() {
  std::lock_guard<std::mutex> guard(*svmap_mu);
  for (auto &iter : svmap) {
    if (iter.second != nullptr) {
      iter.second->UpdateWindow();
    }
  }
}