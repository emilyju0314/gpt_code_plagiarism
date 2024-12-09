Component* Component::GetComponent(const string& name)
{
  NameMap::iterator iter = AllNames.find(name);
  if ( name == "None" || iter == AllNames.end() ) return 0;
  return AllComponents[AllNames[name]].component;
}