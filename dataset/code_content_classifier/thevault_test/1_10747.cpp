Network *Plumbing::GetLayer(const char *id) const {
  char *next_id;
  int index = strtol(id, &next_id, 10);
  if (index < 0 || static_cast<unsigned>(index) >= stack_.size()) {
    return nullptr;
  }
  if (stack_[index]->IsPlumbingType()) {
    auto *plumbing = static_cast<Plumbing *>(stack_[index]);
    ASSERT_HOST(*next_id == ':');
    return plumbing->GetLayer(next_id + 1);
  }
  return stack_[index];
}