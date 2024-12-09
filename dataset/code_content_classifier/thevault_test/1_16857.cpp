void MainWindow::conServer() {

    std::string host = ui->host_le->text().toStdString();
    unsigned int port = (unsigned) ui->port_le->text().toInt();
    std::cout << "Set up connection ..." << std::endl;

    try {

        client = new ClientSocket(host, port);

        QMessageBox::information(this, "Information", "Connection established!");

        connected = true;

        ui->connect_pb->setEnabled(false);
        ui->disconnect_pb->setEnabled(true);

    } catch ( SocketException& e ) {

        std::cout << "SocketException caught with error message: " << e.description() << std::endl;
        QMessageBox::warning(this, "Error", "Connection failed!");

        connected = false;
    }
}