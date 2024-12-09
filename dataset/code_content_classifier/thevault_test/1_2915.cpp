void MainWindow::updateGraphicsReceived()
{
    //pmCamera.loadFromData(qtRosNode->imgCompressed.data(), qtRosNode->imgCompressed.size(), "JPG");
    //giCamera->setPixmap(pmCamera);
    boost::algorithm::to_lower(qtRosNode->str_recognized_speech);
    this->ui->sprLblRecognized->setText(qtRosNode->str_recognized_speech.c_str());
}