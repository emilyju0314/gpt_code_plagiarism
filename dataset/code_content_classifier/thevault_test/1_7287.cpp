int Fl_Check_Browser::checked(int i) const {
	cb_item *p = find_item(i);

	if (p) return p->checked;
	return 0;
}