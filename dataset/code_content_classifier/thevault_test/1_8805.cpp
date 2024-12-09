bool Manager::set_chown()
{
    QProcess passwd, chown;
    passwd.setStandardOutputProcess(&chown);
    passwd.start("echo " + getPassword());
    chown.start("sudo -S chown " + getNew_username() + " /home/" + getNew_username());
    chown.waitForFinished(6000);
    passwd.waitForFinished(6000);
    if(chown.exitCode()!=0)
    {
        return false;
    }
    return true;
}