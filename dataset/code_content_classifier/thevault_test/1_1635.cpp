void MosaicGridTool::configure() {
    MosaicGridToolConfigDialog *configDialog =
        new MosaicGridToolConfigDialog(this,
                                         qobject_cast<QWidget *>(parent()));
    configDialog->setAttribute(Qt::WA_DeleteOnClose);
    configDialog->show();
  }