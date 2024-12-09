ListElement::ListElement(void *itemPtr, float sortKey)
{
  item = itemPtr;
  key = sortKey;
  next = NULL;	// assume we'll put it at the end of the List 
}