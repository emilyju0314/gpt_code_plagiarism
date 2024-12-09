static struct malloc_elem* mempool_find_element(struct malloc_mempool* pool, size_t size) {
  struct malloc_elem* elem = pool->free_head;

  while (elem) {
    // Return the first one once the size is big enough
    if (elem->size >= size) {
      return elem;
    }

    elem = elem->next_free;
  }

  return NULL;
}