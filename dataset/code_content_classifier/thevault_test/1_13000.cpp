RepoMan::~RepoMan()
    {
        closeAll();
        Events::delReceiver(this);
    }