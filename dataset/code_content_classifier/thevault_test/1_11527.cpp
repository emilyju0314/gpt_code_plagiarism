void UTCTask::createFiles(int fileCount)
{
    taskName = "Test";
    watchFolder = kWatchFolder;
    watchDepth = -1;
    // Create task object
    CTask task{watchFolder, testTaskAction1, watchDepth, fileCount};
    // Create task object thread and start to watch
    std::unique_ptr<std::thread> taskThread;
    taskThread = std::make_unique<std::thread>(&CTask::monitor, &task);
    filePath = UTCTask::kWatchFolder;
    for (auto cnt01 = 0; cnt01 < fileCount; cnt01++)
    {
        std::stringstream file;
        file << "temp" << cnt01 << ".txt";
        createFile(filePath + file.str());
    }
    // Thread should die after killCount files created
    taskThread->join();
    EXPECT_EQ(fileCount, testTaskAction1->fileCount);
    for (auto cnt01 = 0; cnt01 < fileCount; cnt01++)
    {
        std::stringstream file;
        file << "temp" << cnt01 << ".txt";
        CFile::remove(filePath + file.str());
    }
}