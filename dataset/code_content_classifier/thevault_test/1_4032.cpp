static void cleanupTempDir(){
    struct stat statbuf;
    timeval now;
    gettimeofday(&now, nullptr);//todo: switch to clock_gettime with CLOCK_MONOTONIC_COARSE, but need to find out how to compare to time from stat

    filesystem::create_directory(TEMP_DIR);
    for (const auto& entry : std::filesystem::directory_iterator(TEMP_DIR)){
        //except fresh files
        if( entry.is_regular_file() &&
            stat(entry.path().c_str(), &statbuf) || // < if error
            (now.tv_sec - statbuf.st_ctim.tv_sec) < TEMP_FILE_OLD_AGE_SECONDS)
                continue;
        std::filesystem::remove_all(entry.path());
    }
}