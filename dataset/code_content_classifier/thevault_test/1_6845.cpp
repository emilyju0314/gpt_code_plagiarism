TORANeighbor*
TORADest::nb_find_max_height()
{
	TORANeighbor *tn = nblist.lh_first;
	TORANeighbor *tn_max = 0;

	for( ; tn; tn = tn->link.le_next) {
		if(tn->height.isNull() == 0) {
			if(tn_max == 0 ||
                           tn_max->height.compare(&tn->height) > 0)
				tn_max = tn;
		}
	}
	return tn_max;
}