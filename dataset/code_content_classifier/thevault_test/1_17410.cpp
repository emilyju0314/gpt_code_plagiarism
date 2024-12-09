static void* cleanup_pid (void* arg)
{
    CleanupInfo* info = (CleanupInfo*)arg;

    // wait for the process to end
    int wstatus = 0;
    waitpid (info->pid, &wstatus, 0);

    pthread_mutex_lock (info->mutex);

    if ((WIFEXITED(wstatus)) && (WEXITSTATUS(wstatus) == 0))
    {
        // if the process succeeded, free the filename
        delete info->filename;
        *info->succeeded_sources += 1;
    }
    else
    {
        // if the process failed, add the source file name to the list of failed sources
        if (*info->failed_sources < MAX_ERRORS)
            info->failed_filenames[*info->failed_sources] = info->filename;
        else
            delete info->filename;
        *info->failed_sources += 1;
    }

    // decrement the number of running processes
    *info->running_procs -= 1;
    pthread_cond_signal (info->cond);
    pthread_mutex_unlock (info->mutex);
    delete info;

    return NULL;
}