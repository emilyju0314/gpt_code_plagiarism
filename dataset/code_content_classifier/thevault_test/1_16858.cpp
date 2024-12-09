void MainWindow::disConServer() {

    if (connected) {

        if (closeFlag)
            QMessageBox::information(this, "Information", "Connection closed!");

        ui->disconnect_pb->setEnabled(false);
        ui->connect_pb->setEnabled(true);

        connected = false;
        client->closeConnection();

    }
}