ListNode* split(ListNode* head, int size)
{
    for (int i = 1; i < size && head != nullptr; i++)
    {
        head = head->next;
    }

    if (head == nullptr)
    {
        return nullptr;
    }

    ListNode* second = head->next;
    head->next = nullptr;

    return second;
}