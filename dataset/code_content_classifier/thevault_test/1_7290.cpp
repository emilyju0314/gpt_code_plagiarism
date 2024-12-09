void Fl_Check_Browser::check_all() {
	cb_item *p;

	nchecked_ = nitems_;
	for (p = first; p; p = p->next) {
		p->checked = 1;
	}
	redraw();
}