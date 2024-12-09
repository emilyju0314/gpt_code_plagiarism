void DiffEventHandler::handle(Event *e) {
	DiffEvent *de = (DiffEvent *)e;
	
	d_handle hdl = de->getHandle();
	queue_->getUID(hdl); // only removes entry from uidmap
	a_->diffTimeout(de);
}