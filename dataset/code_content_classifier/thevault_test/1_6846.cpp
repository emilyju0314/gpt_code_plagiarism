int
TORADest::nb_check_same_ref()
{
	TORANeighbor *tn = nblist.lh_first;
	TORANeighbor *tref = 0;

	for( ; tn; tn = tn->link.le_next) {
		if(tn->height.isNull() == 0) {
			if(tref == 0)
				tref = tn;
			else if(tref->height.tau != tn->height.tau ||
				tref->height.oid != tn->height.oid ||
				tref->height.r != tn->height.r)
				return 0;
		}
	}
	return 1;
}