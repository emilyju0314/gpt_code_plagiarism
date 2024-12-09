int Trie::getCount(vector<int> item_set) {
    Node *tmp = root;
    int len = (int) item_set.size();
    int read = 0;
    for (int i = 0; i < len; i++) {
        int index = item_set[i] - read - 1;
        if (tmp->next[index] == NULL) {
            return 0;
        }
        tmp = tmp->next[index];
        read = item_set[i];
    }
    return tmp->count;
}