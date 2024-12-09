LIST delete_d(LIST list, void *key, int_compare is_equal) {
  LIST result = NIL_LIST;
  LIST last_one = NIL_LIST;

  if (is_equal == nullptr) {
    is_equal = is_same;
  }

  while (list != NIL_LIST) {
    if (!(*is_equal)(list->first_node(), key)) {
      if (last_one == NIL_LIST) {
        last_one = list;
        list = list->list_rest();
        result = last_one;
        set_rest(last_one, NIL_LIST);
      } else {
        set_rest(last_one, list);
        last_one = list;
        list = list->list_rest();
        set_rest(last_one, NIL_LIST);
      }
    } else {
      list = pop(list);
    }
  }
  return (result);
}