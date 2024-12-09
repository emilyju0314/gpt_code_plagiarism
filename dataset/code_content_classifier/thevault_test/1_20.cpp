QtCADQuad::QtCADQuad(QWidget *parent, struct ged *gedpRef, int type) : QWidget(parent)
{
    gedp = gedpRef;
    graphicsType = type;

    views[UPPER_RIGHT] = createView(UPPER_RIGHT);
    bv_set_add_view(&gedp->ged_views, views[UPPER_RIGHT]->view());
    gedp->ged_gvp = views[UPPER_RIGHT]->view();

    // Define the spacers
    spacerTop = new QSpacerItem(3, 0, QSizePolicy::Fixed, QSizePolicy::Expanding);
    spacerBottom = new QSpacerItem(3, 0, QSizePolicy::Fixed, QSizePolicy::Expanding);
    spacerLeft = new QSpacerItem(0, 3, QSizePolicy::Expanding, QSizePolicy::Fixed);
    spacerRight = new QSpacerItem(0, 3, QSizePolicy::Expanding, QSizePolicy::Fixed);
    spacerCenter = new QSpacerItem(3, 3, QSizePolicy::Fixed, QSizePolicy::Fixed);

    views[UPPER_RIGHT]->set_current(1);
    currentView = views[UPPER_RIGHT];

    QObject::connect(views[UPPER_RIGHT], &QtCADView::changed, this, &QtCADQuad::do_view_changed);
}