void
delete_recursively(const char *path)
{
    char *fullpath = const_cast<char *>(path);
    if (*path != '/') {
        char *cwd = getcwd(NULL, 0);
        fullpath = rnp_compose_path(cwd, path, NULL);
        free(cwd);
    }
    /* sanity check, we should only be purging things from /tmp/ */
    assert_true(is_tmp_path(fullpath));

    nftw(path, remove_cb, 64, FTW_DEPTH | FTW_PHYS);
    if (*path != '/') {
        free(fullpath);
    }
}