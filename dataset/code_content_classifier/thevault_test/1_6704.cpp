List::~List()
{ 
  while (Remove() != NULL)
    ;	 // delete all the List elements
}