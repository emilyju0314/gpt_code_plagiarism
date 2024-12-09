void Manager::on_confirm_user_stuff_checkBox_clicked(bool checked)
{
    if(checked)
    {
        // If this box is checked, then set all entered stuff from the user regarding the new user to be created
        setNew_username(ui->new_username_lineEdit->text());
        setNew_user_realname(ui->new_user_real_name_lineEdit->text());
        setNew_user_group(ui->new_user_group_lineEdit->text());
        setNew_user_id(ui->new_user_id_lineEdit->text());
        setNew_user_shell(ui->new_user_shell_lineEdit->text());
        setNew_groupname(ui->new_user_group_lineEdit->text());
        // This functions takes the password as plain text and sets the new_user_enc_password as an encrypted hash
        // of the entered plain text password using openssl
        if(!ui->new_user_password_lineEdit->text().isEmpty())
        {
            // If this check is missing, openssl process is running ... at the background ! Problem !
            create_enc_password();
        }
        // Next check is new_username || new_user_password are empty
        // The other fields can be empty | Doesn't matter so much
        if(getNew_username().isEmpty() || getNew_user_encr_password().isEmpty())
        {
            QMessageBox::information(this, "ERROR", "The username and password for the new user should not be empty!");
            return;
        }
        if(!is_username_valid())
        {
            QMessageBox::warning(this, "ERROR", "Please provide a valid username and try again!");
            return;
        }
        // Show info about the new user that is about to be created. Maybe the operator wants to change some stuff
        QString info("User: " + getNew_username());
        info += !getNew_user_realname().isEmpty() ? "\nReal Name: " + getNew_user_realname() : "";
        info += !getNew_groupname().isEmpty() ? "\nGroup: " + getNew_groupname() : "";
        info += !getNew_user_id().isEmpty() ? "\nID: " + getNew_user_id() : "";
        info += !getNew_user_shell().isEmpty() ? "\nDefault shell: " + getNew_user_shell() : "";
        QMessageBox::information(this, "New created user information", info);
    }
}