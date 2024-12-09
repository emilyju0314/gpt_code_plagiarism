static DLIST *dlist_search(DLIST *head, void *p, int (*comp)(void*, void*))
{
	DLIST *curr;

	if( comp ) {
		for(curr=head; curr; curr=curr->next)
			if( (*comp)(p,curr->p) == 0 )
				return curr;
	} else {
		for(curr=head; curr; curr=curr->next)
			if(p == curr->p)
				return curr;
	}

	return NULL;

}