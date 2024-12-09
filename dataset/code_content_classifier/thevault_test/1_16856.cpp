void MainWindow::closeEvent(QCloseEvent *event) {

    QMessageBox::StandardButton resBtn = QMessageBox::question(this, "ALF", tr("Are you sure to quit?"));

    if (resBtn != QMessageBox::Yes) {

        event->ignore();

    } else {
        closeFlag = false;
        disConServer();
        event->accept();

    }
}