static void
RTreeReInsert(struct Node *n, struct ListNode **ee)
{
    register struct ListNode *l;

    l = RTreeNewListNode();
    l->node = n;
    l->next = *ee;
    *ee = l;
}