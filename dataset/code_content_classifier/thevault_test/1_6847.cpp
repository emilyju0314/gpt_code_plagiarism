void
TORADest::update_height(double TAU, nsaddr_t OID, int R, int DELTA, nsaddr_t ID)
{
	TORANeighbor *tn = nblist.lh_first;

	height.tau = TAU;
	height.oid = OID;
	height.r = R;
	height.delta = DELTA;
	height.id = ID;

#ifdef LOGGING
        agent->log_dst_state_change(this);
#endif
	num_active = num_down = num_up = 0;

	for( ; tn; tn = tn->link.le_next) {

		tn->update_link_status(&height);

		num_active += 1;

		if(tn->lnk_stat == LINK_DN)
			num_down += 1;
		if(tn->lnk_stat == LINK_UP)
			num_up += 1;
	}
}