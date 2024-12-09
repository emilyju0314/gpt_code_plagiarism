void List::Mapcar(VoidFunctionPtr func)
{
  for (ListElement *ptr = first; ptr != NULL; ptr = ptr->next)
    (*func)((long)ptr->item);
}