bool Manager::user_exists()
{
    QProcess proc;
    proc.start("id " + getNew_username());
    proc.waitForFinished();
    if(proc.exitCode()!=0)
    {
        return false;
    }
    return true;
}