void Manager::exit_app()
{
    int checked_action = QMessageBox::question(this, "Quit and close Application ?",
                                               "You are about to exit the Application. Are you sure you want to continue?", QMessageBox::No | QMessageBox::Yes);
    if(checked_action==QMessageBox::Yes) {
        close();
    } else  if(checked_action==QMessageBox::No) {
        return;
    }
}