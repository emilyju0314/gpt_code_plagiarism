inline auto generate_next_color(const std::string& tag) -> uint32_t
{
  // std::unordered_map<std::string, uint32_t> color_gen_state::all_colors_;
  // std::mutex color_gen_state::map_mutex_;

  std::lock_guard<std::mutex> guard(color_gen_state::map_mutex_);
  if (!tag.empty()) {
    auto itr = color_gen_state::all_colors_.find(tag);
    if (itr != color_gen_state::all_colors_.end()) { return itr->second; }
  }
  auto h = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
  h += color_gen_state::kInvPhi;
  if (h >= 1.f) h -= 1.f;
  auto rgb = hsv2rgb(h, color_gen_state::kS, color_gen_state::kV);
  if (!tag.empty()) { color_gen_state::all_colors_[tag] = rgb; }
  return rgb;
}