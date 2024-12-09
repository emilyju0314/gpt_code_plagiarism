bool K2hAttrOpsBase::AddAttrOpArray(k2hattroplist_t& attroplist, K2hAttrOpsBase* pattrop)
{
	if(!pattrop){
		ERR_K2HPRN("parameter is wrong.");
		return false;
	}
	for(k2hattroplist_t::const_iterator iter = attroplist.begin(); iter != attroplist.end(); ++iter){
		if((*iter)->VerInfo == pattrop->VerInfo){
			// found same attrop in list
			ERR_K2HPRN("found same attribute operation object(%s) in list.", pattrop->VerInfo.c_str());
			return false;
		}
	}
	attroplist.push_back(pattrop);

	return true;
}