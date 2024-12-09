bool Manager::del_user_home()
{
    QProcess pass, rm_dir;
    pass.setStandardOutputProcess(&rm_dir);
    pass.start("echo " + getPassword());
    rm_dir.start("sudo -S rm -r /home/" + getNew_username());
    pass.waitForFinished(6000);
    rm_dir.waitForFinished(6000);
    if(rm_dir.exitCode()!=0)
    {
        return false;
    }
    return true;
}