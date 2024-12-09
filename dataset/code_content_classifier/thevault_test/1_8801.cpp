void Manager::on_create_group_button_clicked()
{
    if(!submit_validation)
    {
        QMessageBox::critical(this, "Warning", "Please provide username & password and try again!");
        return;
    }
    if(group_exists()==true)
    {
        QMessageBox::warning(this, "WARNING", "This group already exists in the system. Please try with another one!");
        return;
    }
    // Else create the new group called 'groupname'
    if(groupadd())
    {
        QMessageBox::information(this, "SUCCESS", "The new group: " + getGroupname() + " successfully created!");
        return;
    }
    else {
        QMessageBox::critical(this, "FAILURE", "New group: " + getGroupname() + " failed to be created!");
        return;
    }
}