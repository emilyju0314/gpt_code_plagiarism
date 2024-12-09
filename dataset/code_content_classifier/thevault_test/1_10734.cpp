LIST push_last(LIST list, void *item) {
  LIST t;

  if (list != NIL_LIST) {
    t = last(list);
    t->next = push(NIL_LIST, item);
    return (list);
  } else {
    return (push(NIL_LIST, item));
  }
}