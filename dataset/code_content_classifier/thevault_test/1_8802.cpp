void Manager::on_remove_group_button_clicked()
{
    if(!submit_validation)
    {
        QMessageBox::critical(this, "Warning", "Please provide username & password and try again!");
        return;
    }
    if(!group_exists())
    {
        QMessageBox::warning(this, "WARNING", "This group already does not exist in the system. No need to remove it!");
        return;
    }
    // Else remove it
    if(groupdel())
    {
        QMessageBox::information(this, "SUCCESS", "The group: " + getGroupname() + " successfully removed from the system!");
        return;
    }
    else {
        QMessageBox::critical(this, "FAILURE", "The group: " + getGroupname() + " failed to be removed from the system!");
        return;
    }
}