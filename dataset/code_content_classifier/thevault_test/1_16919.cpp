int init_result(faiss::MetricType metric_type, int k, float *simi, idx_t *idxi) {
  if (metric_type == faiss::METRIC_INNER_PRODUCT) {
    faiss::heap_heapify<HeapForIP> (k, simi, idxi);
  } else {
    faiss::heap_heapify<HeapForL2> (k, simi, idxi);
  }
  return 0;
}