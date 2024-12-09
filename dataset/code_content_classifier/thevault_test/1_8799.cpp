void Manager::cat_users()
{
    QProcess users_proc;
    QString real_users;
    users_proc.start("bash", QStringList() << "-c" << "cut -d: -f1,3 /etc/passwd | egrep ':[0-9]{4}$' | cut -d: -f1");
    if(!users_proc.waitForFinished(3000) || users_proc.exitCode()!=0)
    {
        QMessageBox::critical(this, "ERROR", "Something went wrong. Please try again!");
        return;
    }
    real_users = users_proc.readAllStandardOutput();
    QMessageBox::information(this, "Real System Users", real_users);
    return;
}