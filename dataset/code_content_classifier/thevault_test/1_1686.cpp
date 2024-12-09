bool
check_folder(const std::string& path) {
    struct stat sb;

    if ((stat(path.c_str(), &sb) == 0) && (S_ISDIR(sb.st_mode)) && (sb.st_mode & S_IRUSR) &&
        (sb.st_mode & S_IWUSR)) {
        LOG_INFO_("Folder " + path + " is available and has sufficient rights", "main");
        return true;
    }
    LOG_ERR_("Folder " + path + " has insufficient rights, please check your configuration",
             "main");
    return false;
}