bool Manager::adduser()
{
    QString options;
    QProcess pass, add;
    pass.setStandardOutputProcess(&add);
    pass.start("echo " + getPassword());
    if(!getNew_user_realname().isEmpty())
    {
        options += " -c \"" + getNew_user_realname() + "\"";
    }
    if(!getNew_user_group().isEmpty())
    {
        options += " -g " + getNew_groupname();
    }
    if(!getNew_user_id().isEmpty())
    {
        options += " -u " + getNew_user_id();
    }
    options += " -m -d /home/" + getNew_username();
    if(!getNew_user_shell().isEmpty())
    {
        options += " -s /bin/" + getNew_user_shell();
    }
    options += " -p " + getNew_user_encr_password();
    options += " " + getNew_username();
    add.start("sudo -S useradd " + options);
    add.waitForFinished(-1);
    pass.waitForFinished(6000);
    if(add.exitCode()!=0)
    {
        return false;
    }
    set_chmod();
    set_chown();
    return true;
}