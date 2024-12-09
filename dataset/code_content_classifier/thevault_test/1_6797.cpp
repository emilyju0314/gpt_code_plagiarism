int MultihopMac::checkInterfaces(int state) 
{
	MultihopMac *p;
	
	if (!(mode_ & state))
		return 0;
	else if (macList_ == 0)
		return 1;
	for (p = (MultihopMac *)macList_; p != this && p != NULL; 
	     p = (MultihopMac *)(p->macList())) {
		if (p->mode() != MAC_IDLE) {
			return 0;
		}
	}
	return 1;
}