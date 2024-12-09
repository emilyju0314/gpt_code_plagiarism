void insertAfter(Node **head, int new_node_data, int prev_node_data){
    int d1 = prev_node_data;
    int d2 = new_node_data;
    
    Node *new_node = new Node;
    new_node->data = d2;
    
   if((*head) == NULL){
        new_node->prev = new_node->next = new_node;
        (*head) = new_node;
        return;
      }
    
    Node *temp = (*head);
    
    while(temp->data != d1){
        temp = temp->next;
    }
    
    Node *next = temp->next;
    temp->next = new_node;
    new_node->prev = temp;
    new_node->next = next;
    next->prev = new_node;
    
}