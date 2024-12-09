static
void
uobject_uobjectsPathSet(const rObject&, List::value_type list)
{
  uobjects_path.search_path().clear();
  foreach (rObject p, list)
  {
    rPath path = p->as<object::Path>();
    uobjects_path.search_path().push_back(path->value_get());
  }
}