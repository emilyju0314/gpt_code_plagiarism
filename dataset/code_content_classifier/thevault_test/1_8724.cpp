ListNode* merge(ListNode* l1, ListNode* l2, ListNode* head)
{
    ListNode* current = head;

    // Merge the two input sorted linked lists while neither of l1 and l2 is nullptr.
    while (l1 != nullptr && l2 != nullptr)
    {
        if (l1->val <= l2->val)
        {
            current->next = l1;
            l1 = l1->next;
        }
        else
        {
            current->next = l2;
            l2 = l2->next;
        }

        current = current->next;
    }

    // If either l1 or l2 is not nullptr now, connect it to the current pointer.
    if (l1 != nullptr)
    {
        current->next = l1;
    }
    else if (l2 != nullptr)
    {
        current->next = l2;
    }

    // Find the tail pointer.
    while (current->next != nullptr)
    {
        current = current->next;
    }

    return current;
}