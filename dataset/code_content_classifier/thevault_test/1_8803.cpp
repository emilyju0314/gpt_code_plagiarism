void Manager::on_rename_group_button_clicked()
{
    if(getNew_groupname().isEmpty())
    {
        QMessageBox::warning(this, "ERROR", "Cannot rename group: " + getGroupname() + " to: []! Enter new groupname and try again!");
        return;
    }

    if(!submit_validation)
    {
        QMessageBox::critical(this, "Warning", "Please provide username & password and try again!");
        return;
    }
    if(!group_exists())
    {
        QMessageBox::warning(this, "WARNING", "This group already does not exist in the system!");
        return;
    }
    // Else try to rename this group named getGroupname()
    if(groupmod())
    {
        QMessageBox::information(this, "SUCCESS", "The group: " + getGroupname() + " successfully renamed to: " + getNew_groupname() + " !");
        return;
    }
    else {
        QMessageBox::critical(this, "FAILURE", "The group: " + getGroupname() + " failed to be renamed to: " + getNew_groupname() + " !");
        return;
    }
}