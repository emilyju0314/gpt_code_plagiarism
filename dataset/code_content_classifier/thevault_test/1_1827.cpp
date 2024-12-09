bool    DownloadManager::isValidOverridePath(const std::string& path) {

    //do not allow /../ in the path. This will avoid complicated parsing to check for valid paths
    if (path.find("..") != std::string::npos)
        return false;

    //mkdir -p the path requested just in case
    //LOG_DEBUG ("executing g_mkdir on: %s\n",path.c_str());
    if (g_mkdir_with_parents(path.c_str(), 0755) == -1) {
        LOG_DEBUG ("Function g_mkdir_with_parents() failed");
    }
    //LOG_DEBUG ("g_mkdir exit status = %d\n",exit_status);

    return true;
}