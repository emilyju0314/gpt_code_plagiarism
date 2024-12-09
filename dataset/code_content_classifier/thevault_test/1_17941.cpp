pfwl_ipv6_fragmentation_source_t *
    pfwl_ipv6_fragmentation_find_or_create_source(
        pfwl_ipv6_fragmentation_state_t *state, struct in6_addr addr) {
  uint16_t hash_index = pfwl_ipv6_fragmentation_hash_function(state, addr);
  pfwl_ipv6_fragmentation_source_t *source, *head;

  head = state->table[hash_index];

  for (source = head; source != NULL; source = source->next) {
    if (pfwl_v6_addresses_equal(source->ipv6_srcaddr, addr)) {
      return source;
    }
  }

  /** Not found, so create it. **/
  source = (pfwl_ipv6_fragmentation_source_t *) malloc(
      sizeof(pfwl_ipv6_fragmentation_source_t));
  if (unlikely(source == NULL)) {
    return NULL;
  }
  source->row = hash_index;
  source->flows = NULL;

  source->ipv6_srcaddr = addr;
  source->source_used_mem = sizeof(pfwl_ipv6_fragmentation_source_t);
  state->total_used_mem += sizeof(pfwl_ipv6_fragmentation_source_t);

  /** Insertion at the beginning of the list. **/
  source->prev = NULL;
  source->next = head;
  if (head)
    head->prev = source;
  state->table[hash_index] = source;

  return source;
}