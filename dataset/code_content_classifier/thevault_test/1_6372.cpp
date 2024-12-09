Node *Trie::newNode(int key, int num_child) {
    Node *node = (Node *) malloc(sizeof(node));
    node->key = key;
    node->num_child = num_child;
    node->next = (Node **) malloc(num_child * sizeof(Node *));
    for (int i = 0; i < num_child; i++) {
        node->next[i] = NULL;
    }
    return node;
}