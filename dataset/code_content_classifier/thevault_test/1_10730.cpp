LIST destroy(LIST list) {
  LIST next;

  while (list != NIL_LIST) {
    next = list->list_rest();
    delete list;
    list = next;
  }
  return (NIL_LIST);
}