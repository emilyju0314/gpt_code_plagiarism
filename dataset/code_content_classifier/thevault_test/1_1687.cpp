bool
check_storage_path(const std::string& thumbnail_storage_path) {
    LOG_INFO_("Checking if storage path exists and are usable", "main");
    return (check_folder(thumbnail_storage_path));
}