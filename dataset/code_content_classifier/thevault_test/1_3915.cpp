Node* deleteMid(Node* head)
{
    Node * fast=head,*slow=head,*pr=NULL;
    while(fast!=NULL && fast->next!=NULL)
    {
        fast=fast->next->next;
        pr=slow;
        slow=slow->next;
    }
    pr->next=slow->next;
    delete(slow);
    return head;
}