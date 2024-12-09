Node *newNode(int item, struct TrieNode *address) {

    Node *temp = (Node *)malloc(sizeof(Node)); 
    memory += sizeof(Node) + 8; //Size of Node + Pointer size
    temp->key = item;
    temp->address = address;
    temp->next = NULL;
    return temp;
}