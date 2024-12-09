QGroupBox *DeviceWidget::createDevice()
{
    QGroupBox *gp = new QGroupBox(tr("Title one"), this);
    gp->setStyleSheet("background-color: gray; color: white");

    machineLayout = new QHBoxLayout(gp);


    // Create vm here
    VMWidget *vm = new VMWidget(gp, tr("Title"));
    machineLayout->addWidget(vm->createVM());

    VMWidget *vm1 = new VMWidget(gp, tr("Title"));
    machineLayout->addWidget(vm1->createVM());

    VMWidget *vm2 = new VMWidget(gp, tr("Title"));
    machineLayout->addWidget(vm2->createVM());


    return gp;
}