void PDBLogger::writeLn(std::string writeMe) {

    if (!this->enabled) {
        return;
    }

    const LockGuard guard{fileLock};

    // get the current time and date
    time_t now = time(0);
    struct tm tstruct;
    char buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "[%Y-%m-%d-%X] ", &tstruct);

    // add date and time to the log
    writeMe = buf + writeMe;

    // JiaNote: to get thread id for debugging
    pthread_t threadId = pthread_self();
    if (writeMe[writeMe.length() - 1] != '\n') {
        fprintf(outputFile, "[%lu]%s\n", threadId, writeMe.c_str());
    } else {
        fprintf(outputFile, "[%lu]%s", threadId, writeMe.c_str());
    }
    fflush(outputFile);
}