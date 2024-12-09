bool Delete(const FilePath& path, bool recursive)
{
    //const char* path_str= path.value().utf8().data();
    stat_wrapper_t file_info;
    int test = CallStat(path.value().utf8().data(), &file_info);
    if (test != 0) {
        // md_debug("*********** file [%s] stat error ****************\n", path.value().utf8().data());
        // The Windows version defines this condition as success.
        bool ret = (errno == ENOENT || errno == ENOTDIR);
        return ret;
    }
    if (!S_ISDIR(file_info.st_mode))
    {
        if (WebCore::unlinkFile(path.value().utf8().data()) == 0) {
            // md_debug("*** file [%s] delete SUCCEED **********\n", path.value().utf8().data());
            return true;
        } else {
            // md_debug("*** file [%s]delete FAILED**********\n", path.value().utf8().data());
            return false;
        }
    }
    if (!recursive)
        return (WebCore::rmdirFile(path.value().utf8().data()) == 0);

    bool success = true;
    Vector<String> directories;
    directories.append(path.value());
    FileEnumerator traversal(path, true, static_cast<FileEnumerator::FILE_TYPE>(
                FileEnumerator::FILES | FileEnumerator::DIRECTORIES |
                FileEnumerator::SHOW_SYM_LINKS));
    for (FilePath current = traversal.Next(); success && !current.empty();
            current = traversal.Next()) {
        FileEnumerator::FindInfo info;
        traversal.GetFindInfo(&info);

        if (S_ISDIR(info.stat.st_mode))
            directories.append(current.value());
        else
            success = (WebCore::unlinkFile(current.value().utf8().data()) == 0);
    }

    while (success && !directories.isEmpty()) {
        FilePath dir = FilePath(directories.last());
        directories.removeLast();
        success = (WebCore::rmdirFile(dir.value().utf8().data()) == 0);
    }
    return success;
}