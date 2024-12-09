RackWidget *RackSystem::createRack()
{
    QString title = "Title one";
    RackWidget *rw = new RackWidget(this, 10, title);

    return rw;
}