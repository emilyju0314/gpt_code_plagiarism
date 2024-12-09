bool Manager::compare_passwords()
{
    if(getPassword() != ui->retype_password_lineEdit->text())
    {
        return false;
    }
    return true;
}