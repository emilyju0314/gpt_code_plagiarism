static int dlist_count(DLIST *head)
{
	int i;

	i = 0;
	while( head ) {
		head = head->next;
		i++;
	}

	return i;
}