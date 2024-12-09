void RepoMan::closeAll()
    {
        RM_D(RepoMan);

        foreach(Repo* repo, d->repos) {
            repo->close();
        }
    }