void MainUI::AvailableMultimediaFiles(QStringList files){
  if(!files.isEmpty()){
    ui->combo_player_list->clear();
    ui->combo_player_list->addItems(files);
    ui->tool_goToPlayer->setVisible(true);
  }else{
    ui->tool_goToPlayer->setVisible(false);
  }
  
}