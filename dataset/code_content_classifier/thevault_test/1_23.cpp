void
QtCADQuad::changeToSingleFrame()
{
    QGridLayout *layout = (QGridLayout *)this->layout();
    if (layout == nullptr) {
	layout = createLayout();
    }
    while (layout->takeAt(0) != NULL);
    layout->addWidget(views[UPPER_RIGHT], 0, 2);

    for (int i = 1; i < 4; i++) {
	// Don't want use cpu for views that are not visible
	if (views[i] != nullptr) {
	    views[i]->disconnect();
	    bv_set_rm_view(&gedp->ged_views, views[i]->view());
	    delete views[i];
	    views[i] = nullptr;
	}
    }

    views[UPPER_RIGHT]->set_current(1);
    currentView = views[UPPER_RIGHT];
    // This is only used in quad mode
    currentView->select(0);

    default_views();
}