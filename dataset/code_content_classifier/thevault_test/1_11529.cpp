TEST_F(UTCTask, ActionFunctionException)
{
    taskName = "Test";
    watchFolder = kWatchFolder;
    fileName = "tmp.txt";
    watchDepth = -1;
    // Create task object
    CTask task{watchFolder, testTaskAction2, watchDepth, 0};
    // Create task object thread and start to watch
    std::unique_ptr<std::thread> taskThread;
    taskThread = std::make_unique<std::thread>(&CTask::monitor, &task);
    // Create one file to trigger action function
    createFile(watchFolder + fileName);
    // Thread should die after killCount files created
    taskThread->join();
    EXPECT_THROW(generateException(task.getThrownException()), std::logic_error);
    if (CFile::exists(watchFolder + fileName))
    {
        CFile::remove(watchFolder + fileName);
    }
}