void Manager::init()
{
    setUsername("");
    setPassword("");
    // Username can be visible
    ui->username_lineEdit->setEchoMode(QLineEdit::Normal);
    // Password should not be visible by default
    ui->password_lineEdit->setEchoMode(QLineEdit::Password);
    ui->retype_password_lineEdit->setEchoMode(QLineEdit::Password);
    // Also the password for the new user who will be created should not
    // be visible by default
    ui->new_user_password_lineEdit->setEchoMode(QLineEdit::Password);
}