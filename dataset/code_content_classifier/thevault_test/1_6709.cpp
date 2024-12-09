void *List::SortedRemove(float *keyPtr)
{
  ListElement *element = first;
  void *thing;
  
  if (IsEmpty()) 
    return NULL;
  
  thing = first->item;
  if (first == last) 
    {				// List had one item, now has none 
      first = NULL;
      last = NULL;
    } 
  else 
    first = element->next;

  if (keyPtr != NULL)
    *keyPtr = element->key;
  delete element;
  
  size--;
  return thing;
}