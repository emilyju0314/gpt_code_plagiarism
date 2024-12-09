char *Fl_Check_Browser::text(int i) const {
	cb_item *p = find_item(i);

	if (p) return p->text;
	return 0;
}