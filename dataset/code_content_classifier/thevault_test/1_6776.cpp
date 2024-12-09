void Group::get_members(int *mbrs)
{
	Tcl_HashEntry *he;
	Tcl_HashSearch hs;
	int i = 0;
	for (he = Tcl_FirstHashEntry(nodeHash_, &hs);
	     he != NULL;
	     he = Tcl_NextHashEntry(&hs), i++) 
		mbrs[i] = *Tcl_GetHashValue(he);
}