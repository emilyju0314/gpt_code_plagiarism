void Fl_Check_Browser::check_none() {
	cb_item *p;

	nchecked_ = 0;
	for (p = first; p; p = p->next) {
		p->checked = 0;
	}
	redraw();
}