void* cart_delete(cart_tree *t, const unsigned char *key, int key_len) {
    cart_leaf *l = recursive_delete(t->root, &t->root, key, key_len, 0);
    if (l) {
        t->size--;
        void *old = l->value;
        free(l);
        return old;
    }
    return NULL;
}