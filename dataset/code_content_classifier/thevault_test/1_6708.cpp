void List::SortedInsert(void *item, float sortKey)
{
  ListElement *element = new ListElement(item, sortKey);
  ListElement *ptr;	        // keep track
  
  if (IsEmpty()) 
    {				// List is empty, put in front
      first = element;
      last = element;
    } 
  else if (sortKey < first->key) 
    {				// item goes on front of List	
      element->next = first;
      first = element;
    } 
  else 
    {				// look for first elt in List bigger than item
      for (ptr = first; ptr->next != NULL; ptr = ptr->next) {
	if (sortKey < ptr->next->key) 
	  {
	    element->next = ptr->next;
	    ptr->next = element;
	    return;
	  }	
      }
      last->next = element;	// item goes at end of List
      last = element;
    }
  
  size++;
}