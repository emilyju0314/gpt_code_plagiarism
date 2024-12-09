static DLIST *dlist_new(void *p)
{
	DLIST *newp;

	newp = (DLIST *) malloc( sizeof(DLIST) );

	if( newp == NULL) {
		return NULL;
	}

	newp->p = p;
	newp->prev = NULL;
	newp->next = NULL;
	return newp;
}