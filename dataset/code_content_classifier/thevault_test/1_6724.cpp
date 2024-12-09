void Tag::xdraw(View *v, double now) const 
{
	// Draw every object of this group
	Tcl_HashEntry *he;
	Tcl_HashSearch hs;
	Animation *a;

	for (he = Tcl_FirstHashEntry(mbrHash_, &hs);
	     he != NULL;
	     he = Tcl_NextHashEntry(&hs)) {
		a = (Animation *) Tcl_GetHashValue(he);
		a->draw(v, now);
	}
}