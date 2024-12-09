bool LsRouting::isUp(int neighborId) 
{
	if (linkStateListPtr_ == NULL) 
		return false;

	for (LsLinkStateList::iterator itr = linkStateListPtr_->begin();
	     itr!= linkStateListPtr_->end(); itr++)
		if ((*itr).neighborId_ == neighborId)
			return ((*itr).status_ == LS_STATUS_UP) ? true : false;
	return false;
}