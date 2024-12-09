ListNode* create_list(int val_list[], int length)
{
    ListNode* head = new ListNode(val_list[0]);
    ListNode* current = head;

    for (size_t i = 1; i < length; i++)
    {
        current->next = new ListNode(val_list[i]);
        current = current->next;
    }

    return head;
}