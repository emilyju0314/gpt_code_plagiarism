bool Manager::compare_usernames()
{
    QString current_user = getenv("USER");
    if(getUsername()!=current_user)
    {
        return false;
    }
    return true;
}