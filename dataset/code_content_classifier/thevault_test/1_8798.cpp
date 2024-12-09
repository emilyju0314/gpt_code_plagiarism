void Manager::on_submit_button_clicked()
{
    // Grab the username & password at first
    setUsername(ui->username_lineEdit->text());
    setPassword(ui->password_lineEdit->text());
    // If the username or password is empty prompt to enter them
    if(getUsername().isEmpty() || getPassword().isEmpty() || ui->retype_password_lineEdit->text().isEmpty())
    {
        QMessageBox::warning(this, "WARNING", "Username and password should be both specified!");
        return;
    }
    // Username should be the currently logged user's
    if(!compare_usernames())
    {
        QMessageBox::critical(this, "ERROR", "Please provide correct username and try again!");
        return;
    }
    // Next check if the provided password is correct
    // Just execute a trivial 'ls' command using sudo. If it succeeds, password is ok. Otherwise, password is false!
    if(!compare_passwords())
    {
        QMessageBox::critical(this, "ERROR", "Passwords do not match. Try again!");
        return;
    }
    // Checks are ok by now.
    submit_validation = true;
    QMessageBox::information(this, "INFO", "Credentials entered. Continue procedure ...");
}