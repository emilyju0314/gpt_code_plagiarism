static DLIST *dlist_add(DLIST **head, void *p)
{
	DLIST *curr;

	if( *head == NULL ) {
		*head = dlist_new(p);
		return *head;
	} else {
		for (curr = *head; curr->next; curr = curr->next)
		    ;

		curr->next = dlist_new(p);
		if( curr->next == NULL )
			return NULL;
		curr->next->prev = curr;
		return curr->next;
	}
}