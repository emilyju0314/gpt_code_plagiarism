void Trie::insertAll(Node *root, vector<int> item_set, int k, int limit, int count) {
    for (int i = 0; i < k; i++) {
        root = insertOne(root, item_set[i], limit - item_set[i]);
    }
    root->count = count;
}