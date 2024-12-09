void *SqliteMemoryManager::GetMemory(int size) {
  void *p = malloc_arenas_[idx_last_arena_]->Malloc(size);
  if (p != NULL)
    return p;
  unsigned N = malloc_arenas_.size();
  for (unsigned i = 0; i < N; ++i) {
    p = malloc_arenas_[i]->Malloc(size);
    if (p != NULL) {
      idx_last_arena_ = i;
      return p;
    }
  }
  idx_last_arena_ = N;
  MallocArena *M = new MallocArena();
  malloc_arenas_.push_back(M);
  p = M->Malloc(size);
  assert(p != NULL);
  return p;
}