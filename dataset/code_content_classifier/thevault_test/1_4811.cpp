BencEntity *BencodedList::Append(BencEntity &e)
{
	assert(bencType == BENC_LIST);
	assert(list);
	list->push_back(e);
	return &((*list)[(list->size())-1]);
}