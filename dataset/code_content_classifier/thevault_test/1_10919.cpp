void RecodeBeamSearch::PushHeapIfBetter(int max_size, int code, int unichar_id,
                                        PermuterType permuter, bool dawg_start,
                                        bool word_start, bool end, bool dup,
                                        float cert, const RecodeNode *prev,
                                        DawgPositionVector *d,
                                        RecodeHeap *heap) {
  float score = cert;
  if (prev != nullptr) {
    score += prev->score;
  }
  if (heap->size() < max_size || score > heap->PeekTop().data().score) {
    uint64_t hash = ComputeCodeHash(code, dup, prev);
    RecodeNode node(code, unichar_id, permuter, dawg_start, word_start, end,
                    dup, cert, score, prev, d, hash);
    if (UpdateHeapIfMatched(&node, heap)) {
      return;
    }
    RecodePair entry(score, node);
    heap->Push(&entry);
    ASSERT_HOST(entry.data().dawgs == nullptr);
    if (heap->size() > max_size) {
      heap->Pop(&entry);
    }
  } else {
    delete d;
  }
}