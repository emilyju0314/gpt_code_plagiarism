void MainWindow::saveMap() {
    Commands save_map = SAVE_MAP;
    if (connected)
        client->sending(save_map);
}