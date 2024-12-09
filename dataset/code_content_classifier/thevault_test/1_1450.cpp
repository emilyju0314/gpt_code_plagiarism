int art_node_lock(art_node *an)
{
  while (1) {
    // must use `acquire` operation to avoid deadlock
    uint64_t version = art_node_get_version(an);
    if (is_locked(version)) {
      // __asm__ __volatile__ ("pause");
      continue;
    }
    if (unlikely(is_old(version)))
      return 1;
    if (__atomic_compare_exchange_n(&an->version, &version, set_lock(version),
      1 /* weak */, __ATOMIC_RELEASE, __ATOMIC_RELAXED))
      break;
  }
  return 0;
}