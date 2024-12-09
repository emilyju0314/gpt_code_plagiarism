bool LsTopoMap::update(int nodeId, 
		       const LsLinkStateList& linkStateList)
{
	LsLinkStateList * LSLptr = findPtr (nodeId);
	if (LSLptr == NULL) {
		insert(nodeId, linkStateList);
		return true;
	}

	bool retCode = false;
	LsLinkStateList::iterator itrOld;
	for (LsLinkStateList::const_iterator itrNew = linkStateList.begin();
	     itrNew != linkStateList.end(); itrNew++ ) {
  
		for (itrOld = LSLptr->begin();
		     itrOld != LSLptr->end(); itrOld++) {

			if ((*itrNew).neighborId_ == (*itrOld).neighborId_) {
				// old link state found
				if (nodeId != myNodeId_)
					// update the sequence number, if 
					// it's not  my own link state
					(*itrOld).sequenceNumber_ = 
						(*itrNew).sequenceNumber_;
				if ((*itrNew).status_ != (*itrOld).status_) {
					(*itrOld).status_ = (*itrNew).status_;
					retCode = true;
				}
				if ((*itrNew).cost_ != (*itrOld).cost_) {
					(*itrOld).cost_ = (*itrNew).cost_;
					retCode = true;
				}
				break; // no need to search for more old link state;
			} // end if old link state found
		} // end for old link states
		if (itrOld == LSLptr->end()) {
			// no old link found
			LSLptr->push_back(*itrNew);
			retCode = true;
		}
	}// end for new link states 
	return retCode;
}