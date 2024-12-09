LIST search(LIST list, void *key, int_compare is_equal) {
  if (is_equal == nullptr) {
    is_equal = is_same;
  }

  iterate(list) if ((*is_equal)(list->first_node(), key)) return list;
  return (NIL_LIST);
}