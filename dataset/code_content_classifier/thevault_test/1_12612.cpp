Component* Component::GetComponent(CompId_t id)
{
  if ( id >= (signed int)AllComponents.size() || id < 0 ) return 0;
  return AllComponents[id].component;
}