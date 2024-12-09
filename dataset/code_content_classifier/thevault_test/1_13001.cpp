Repo* RepoMan::open(const QString& path)
    {
        Git::Result result;
        Git::Repository repo = Git::Repository::open( result, path );
        if( !result || !repo.isValid() )
        {
            return NULL;
        }

        return open( repo );
    }