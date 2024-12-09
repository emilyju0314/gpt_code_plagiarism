QtCADView *
QtCADQuad::createView(int index)
{
    QtCADView *view = new QtCADView(this, graphicsType);
    bu_vls_sprintf(&view->view()->gv_name, "%s", VIEW_NAMES[index]);
    view->set_current(0);
    view->installEventFilter(this);

    view->view()->vset = &gedp->ged_views;
    view->view()->independent = 0;

    return view;
}