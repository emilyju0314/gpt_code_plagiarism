void output_list(ListNode* list)
{
    while (list != nullptr)
    {
        std::cout << list->val << std::endl;
        list = list->next;
    }
}