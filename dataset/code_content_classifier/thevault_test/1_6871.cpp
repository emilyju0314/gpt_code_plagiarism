scheduler_uid_t DiffEventQueue::getUID(d_handle hdl) {
	UIDMap_t::iterator itr;
	MapEntry* entry;
	for (itr = uidmap_.begin(); itr != uidmap_.end(); ++itr) {
		entry = *itr;
		if (entry->hdl_ == hdl) { // found handle
			// don't need this entry, take it out of list
			scheduler_uid_t uid = entry->uid_;
			itr = uidmap_.erase(itr);
			delete entry;
			return uid;
		}
	}
	return (-1);
}