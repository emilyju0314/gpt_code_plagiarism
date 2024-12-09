void List::Prepend(void *item)
{
  ListElement *element = new ListElement(item, 0);
  
  if (IsEmpty()) 
    {				// List is empty
      first = element;
      last = element;
    } 
  else 
    {				// else put it before first
      element->next = first;
      first = element;
    }

  size++;
}