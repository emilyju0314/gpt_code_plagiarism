static inline int leaf_matches(const cart_leaf *n, const unsigned char *key, int key_len, int depth) {
    // Fail if the key lengths are different
    // Compare the keys stcarting at the depth
    // if (n->key_len == (uint32_t)key_len && (*(uint64_t*)n->key) == (*(uint64_t*)key)) 
    return !(n->key_len == (uint32_t)key_len && memcmp(n->key, key, key_len) == 0);
}