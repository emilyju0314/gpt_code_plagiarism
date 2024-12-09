const RepoAuthType::Array* Builder::insert(RepoAuthType::Array* cand) {
  assertx(cand->id() == -1u);
  std::lock_guard<std::mutex> g(m_impl->mutex);
  auto ins = m_impl->types.insert(cand);
  if (ins.second) {
    cand->m_id = m_impl->nextId++;
    assertx(*ins.first == cand);
    assertx((*ins.first)->id() == cand->id());
    return cand;
  }
  return *ins.first;
}