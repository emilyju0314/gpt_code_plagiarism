void Manager::on_show_password_checkBox_clicked(bool checked)
{
    if(checked)
    {
        // If user clicks this checkbox the password is shown
        ui->password_lineEdit->setEchoMode(QLineEdit::Normal);
        ui->retype_password_lineEdit->setEchoMode(QLineEdit::Normal);
    }
    else {
        // If this checkbox is un-checked, please hide the password
        ui->password_lineEdit->setEchoMode(QLineEdit::Password);
        ui->retype_password_lineEdit->setEchoMode(QLineEdit::Password);
    }
}