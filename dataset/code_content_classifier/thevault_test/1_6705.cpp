void List::Append(void *item)
{
  ListElement *element = new ListElement(item, 0);
  if (IsEmpty()) 
    {				// List is empty
      first = element;
      last = element;
    } 
  else 
    {				// else put it after last
      last->next = element;
      last = element;
    }
  
  size++;
}