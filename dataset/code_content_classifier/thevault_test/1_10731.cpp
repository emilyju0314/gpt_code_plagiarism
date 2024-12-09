LIST last(LIST var_list) {
  while (var_list->list_rest() != NIL_LIST) {
    var_list = var_list->list_rest();
  }
  return var_list;
}