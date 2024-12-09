bool IsTopRoot(const EventNode* event) {
  if (event->GetGroupId().has_value()) return false;
  for (EventNode* cur = event->GetParent(); cur != nullptr;
       cur = cur->GetParent()) {
    if (cur->IsRoot()) return false;
  }
  return true;
}