TORANeighbor*
TORADest::nb_find_min_height(int R)
{
	TORANeighbor *tn = nblist.lh_first;
	TORANeighbor *tn_min = 0;

	for( ; tn; tn = tn->link.le_next) {
		if(tn->height.r == R) {
			if(tn_min == 0 ||
                           tn_min->height.compare(&tn->height) < 0)
				tn_min = tn;
		}
	}
	return tn_min;
}