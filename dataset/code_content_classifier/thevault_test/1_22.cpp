QGridLayout *
QtCADQuad::createLayout()
{
    QGridLayout *layout = new QGridLayout(this);
    layout->setSpacing(0);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setAlignment(Qt::AlignTop | Qt::AlignLeft);

    this->setLayout(layout);

    if (currentLayout != nullptr) {
	delete currentLayout;
    }
    currentLayout = layout;

    return layout;
}