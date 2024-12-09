LIST pop(LIST list) {
  LIST temp = list->list_rest();
  delete list;
  return temp;
}