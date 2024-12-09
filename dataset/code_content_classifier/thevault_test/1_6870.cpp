void DiffEventQueue::setUID(d_handle hdl, scheduler_uid_t uid) {
	MapEntry *me = new MapEntry;
	me->hdl_ = hdl;
	me->uid_ = uid;
	uidmap_.push_back(me);
}