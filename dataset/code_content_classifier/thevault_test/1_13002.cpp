Repo* RepoMan::open(const Git::Repository& gitRepo)
    {
        RM_D(RepoMan);

        Repo* repo = repoByPath(gitRepo.workTreePath(), false);

        if(!repo) {
            repo = new Repo(gitRepo, this);
            d->repos.append(repo);

            Events::self()->repositoryOpened(repo);

            if (d->repos.count() == 1) {
                emit firstRepositoryOpened();
            }
        }

        activate( repo );
        return repo;
    }