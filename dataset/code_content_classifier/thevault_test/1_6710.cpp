float List::MinKey()
{
  if (IsEmpty())
    return -1;
  else
    return first->key;
}