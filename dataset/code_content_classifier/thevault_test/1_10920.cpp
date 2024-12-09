void RecodeBeamSearch::PushHeapIfBetter(int max_size, RecodeNode *node,
                                        RecodeHeap *heap) {
  if (heap->size() < max_size || node->score > heap->PeekTop().data().score) {
    if (UpdateHeapIfMatched(node, heap)) {
      return;
    }
    RecodePair entry(node->score, *node);
    heap->Push(&entry);
    ASSERT_HOST(entry.data().dawgs == nullptr);
    if (heap->size() > max_size) {
      heap->Pop(&entry);
    }
  }
}