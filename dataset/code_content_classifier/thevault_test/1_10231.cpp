void PrependFragment(string* s, bool* changed) {
  impala::ThreadDebugInfo* tdi = impala::GetThreadDebugInfo();
  if (tdi != nullptr) {
    for (auto id : { tdi->GetInstanceId(), tdi->GetQueryId() }) {
      if (id == ZERO_UNIQUE_ID) continue;
      s->insert(0, PrintId(id) + "] ");
      if (changed != nullptr) *changed = true;
      return;
    }
  }
}