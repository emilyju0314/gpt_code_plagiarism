Node *Trie::insertOne(Node *root, int key, int num_child) {
    int index = key - root->key - 1;
    if (root->next[index] == NULL) {
        Node *node = newNode(key, num_child);
        root->next[index] = node;
    }
    return root->next[index];
}