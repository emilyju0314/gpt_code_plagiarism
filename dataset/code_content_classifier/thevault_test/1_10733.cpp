LIST push(LIST list, void *element) {
  LIST t;

  t = new list_rec;
  t->node = static_cast<LIST>(element);
  set_rest(t, list);
  return (t);
}