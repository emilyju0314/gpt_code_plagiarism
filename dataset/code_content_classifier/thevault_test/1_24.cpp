void
QtCADQuad::changeToQuadFrame()
{
    for (int i = 1; i < 4; i++) {
	if (views[i] == nullptr) {
	    views[i] = createView(i);
	}
	bv_set_add_view(&gedp->ged_views, views[i]->view());
	QObject::connect(views[i], &QtCADView::changed, this, &QtCADQuad::do_view_changed);
    }
    QGridLayout *layout = (QGridLayout *)this->layout();
    if (layout == nullptr) {
	layout = createLayout();
    }
    while (layout->takeAt(0) != NULL);

    layout->addWidget(views[UPPER_LEFT], 0, 0);
    layout->addItem(spacerTop, 0, 1);
    layout->addWidget(views[UPPER_RIGHT], 0, 2);
    layout->addItem(spacerLeft, 1, 0);
    layout->addItem(spacerCenter, 1, 1);
    layout->addItem(spacerRight, 1, 2);
    layout->addWidget(views[LOWER_LEFT], 2, 0);
    layout->addItem(spacerBottom, 2, 1);
    layout->addWidget(views[LOWER_RIGHT], 2, 2);

    default_views();

    // Not sure if this is the right way to do this but need to autoset each of the views
    const char *av[2];
    av[0] = "autoview";
    av[1] = (char *)0;
    for (int i = 1; i < 4; i++) {
	gedp->ged_gvp = views[i]->view();
	ged_exec(gedp, 1, (const char **)av);
    }
    gedp->ged_gvp = views[UPPER_RIGHT]->view();
    views[UPPER_RIGHT]->set_current(1);
    currentView = views[UPPER_RIGHT];
    // This is only used in quad mode
    currentView->select(1);
}