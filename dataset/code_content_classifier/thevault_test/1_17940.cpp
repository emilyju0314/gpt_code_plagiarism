pfwl_ipv6_fragmentation_state_t *
pfwl_reordering_enable_ipv6_fragmentation(uint16_t table_size) {
  pfwl_ipv6_fragmentation_state_t *r =
      (pfwl_ipv6_fragmentation_state_t *) calloc(
          1, sizeof(pfwl_ipv6_fragmentation_state_t));
  if (r == NULL) {
    return NULL;
  }
  r->table_size = table_size;
  r->table = (pfwl_ipv6_fragmentation_source_t **) malloc(
      table_size * sizeof(pfwl_ipv6_fragmentation_source_t *));
  if (r->table == NULL) {
    free(r);
    return NULL;
  }
  uint16_t i;
  for (i = 0; i < table_size; i++) {
    r->table[i] = NULL;
  }
  r->timer_head = NULL;
  r->timer_tail = NULL;
  r->per_source_memory_limit =
      PFWL_IPv6_FRAGMENTATION_DEFAULT_PER_HOST_MEMORY_LIMIT;
  r->total_memory_limit = PFWL_IPv6_FRAGMENTATION_DEFAULT_TOTAL_MEMORY_LIMIT;
  r->timeout = PFWL_IPv6_FRAGMENTATION_DEFAULT_REASSEMBLY_TIMEOUT;
  r->total_used_mem = 0;
#if PFWL_THREAD_SAFETY_ENABLED == 1
  ff::init_unlocked(r->lock);
#endif
  return r;
}