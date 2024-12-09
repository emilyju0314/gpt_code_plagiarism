int art_node_prefix_compare(art_node *an, uint64_t version, const void *key, size_t len, size_t off)
{
  debug_assert(off <= len);

  int prefix_len = get_prefix_len(version);
  const char *prefix = an->prefix, *cur = (const char *)key;
  debug_assert(prefix_len >= 0 && prefix_len <= 8);

  int i = 0;
  for (; i < prefix_len && off < len; ++i, ++off) {
    if (prefix[i] != cur[off])
      return i;
  }

  return i;
}