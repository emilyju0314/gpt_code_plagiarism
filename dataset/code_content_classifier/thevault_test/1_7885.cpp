static DLIST *dlist_delete(DLIST **head, void* p, void (*destroy)(void*),
							int (*comp)(void*, void*))
{
	DLIST *curr;
	DLIST *rtn;

	if (*head == NULL)
		return NULL;

	if(comp) {
		if( (*comp)(p, (*head)->p) == 0 ) {
			if( destroy )
				(*destroy)((*head)->p);
			rtn = (*head)->next;
			free(*head);

			if(rtn)
				rtn->prev = NULL;

			*head = rtn;
			return rtn;
		}

		for(curr=*head; curr; curr=curr->next) {
			if( (*comp)(p, curr->p) == 0 ) {
				curr->prev->next = curr->next;
			    
				if (curr->next)
					curr->next->prev = curr->prev;
			    
				rtn = curr->next;
				if( destroy )
					(*destroy)(curr->p);
				free(curr);
				return rtn;
			}
		}
		return NULL;
	}

	if( (*head)->p == p) {
		if( destroy )
			(*destroy)((*head)->p);
		rtn = (*head)->next;
		free(*head);

		if(rtn)
			rtn->prev = NULL;

		*head = rtn;
		return rtn;
	}

	for(curr=*head; curr; curr=curr->next) {
		if(curr->p == p) {
			curr->prev->next = curr->next;

			if (curr->next)
				curr->next->prev = curr->prev;

			rtn = curr->next;
			if( destroy )
				(*destroy)(curr->p);
			free(curr);
			return rtn;
		}
	}
	return NULL;
}